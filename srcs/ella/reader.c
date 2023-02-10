/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:44:25 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/10 09:53:12 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	change_cursor_pos_after_char_remove(t_shell *data)
{
	if (data->input_len + data->prmpt_len > data->window_columns
		&& data->tcaps.cursor_y >= data->window_rows)
		data->tcaps.cursor_y--;
	else if (data->tcaps.cursor_x - 1 < 0)
	{
		if (data->tcaps.cursor_y - 1 > -1)
			data->tcaps.cursor_y--;
		data->tcaps.cursor_x = data->window_columns;
	}
	if (data->tcaps.cursor_y != data->tcaps.start_cursor_y
		|| (data->tcaps.cursor_y == data->tcaps.start_cursor_y
			&& data->tcaps.cursor_x > data->prmpt_len))
		data->tcaps.cursor_x--;
	data->input_len--;
}

static void	copy_and_remove(t_shell *data, char *str, int wanted_x)
{
	int		i;
	int		x;
	char	tmp1[BUFFER];
	int		len;

	i = 0;
	x = 0;
	ft_bzero(tmp1, BUFFER);
	len = ft_strlen(str);
	while (i < BUFFER && i < wanted_x)
		tmp1[x++] = str[i++];
	i++;
	while (i < BUFFER && i < len)
		tmp1[x++] = str[i++];
	ft_bzero(str, BUFFER);
	i = 0;
	while (tmp1[i] != '\0')
	{
		str[i] = tmp1[i];
		i++;
	}
	str[i] = '\0';
	change_cursor_pos_after_char_remove(data);
}

int	count_input_rows(t_shell *data)
{
	int	times;
	int	i;

	times = 0;
	i = data->input_len + data->prmpt_len + data->tcaps.start_cursor_x;
	while (i > 0)
	{
		times++;
		i -= data->window_columns;
	}
	data->input_rows = times;
	return (times);
}

static void	change_cursor_pos_after_char_added(t_shell *data)
{
	data->input_len++;
	count_input_rows(data);
	if ((data->tcaps.start_cursor_y != data->tcaps.cursor_y
			&& data->tcaps.cursor_x + 1 < (data->input_len + data->prmpt_len
				+ 1) - ((data->tcaps.cursor_y - data->tcaps.start_cursor_y)
				* data->window_columns)) || (data->tcaps.start_cursor_y
			== data->tcaps.cursor_y && data->tcaps.cursor_x + 1
			< (data->input_len + data->prmpt_len + 1)))
	{
		if (data->tcaps.cursor_x + 1 == data->window_columns)
		{
			if (data->tcaps.cursor_y + 1 < data->window_rows)
			{
				data->tcaps.cursor_x = 0;
				data->tcaps.cursor_y++;
			}
		}
		else
			data->tcaps.cursor_x++;
	}
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.cursor_y), 1, stdin_char);
}

static void	copy_and_add(t_shell *data, char *str, char c, int wanted_x)
{
	int		i;
	int		x;
	int		len;
	char	tmp1[BUFFER];

	i = 0;
	x = 0;
	len = (int)ft_strlen(str);
	ft_bzero(tmp1, BUFFER);
	while (i < BUFFER && i < wanted_x)
		tmp1[x++] = str[i++];
	tmp1[x++] = c;
	while (i < BUFFER && i < len)
		tmp1[x++] = str[i++];
	ft_bzero(str, BUFFER);
	i = 0;
	while (tmp1[i] != '\0')
	{
		str[i] = tmp1[i];
		i++;
	}
	str[i] = '\0';
	change_cursor_pos_after_char_added(data);
}

void	add_char_in_string(t_shell *data, char c)
{
	int		wanted_x;

	wanted_x = 0;
	if (data->tcaps.cursor_y != data->tcaps.start_cursor_y)
		wanted_x = ((data->tcaps.cursor_y - data->tcaps.start_cursor_y)
				* data->window_columns) + data->tcaps.cursor_x
			- data->prmpt_len - data->tcaps.start_cursor_x;
	else
		wanted_x = data->tcaps.cursor_x - data->prmpt_len
			- data->tcaps.start_cursor_x;
	copy_and_add(data, data->input[0], c, wanted_x);
}

void	remove_char_in_string(t_shell *data)
{
	int	wanted_x;

	wanted_x = 0;
	if (data->tcaps.cursor_y != data->tcaps.start_cursor_y)
		wanted_x = ((data->tcaps.cursor_y - data->tcaps.start_cursor_y)
				* data->window_columns)
			+ data->tcaps.cursor_x + data->tcaps.start_cursor_x
			- data->prmpt_len - 1 - data->tcaps.start_cursor_x;
	else
		wanted_x = data->tcaps.cursor_x - data->prmpt_len - 1
			- data->tcaps.start_cursor_x;
	copy_and_remove(data, data->input[0], wanted_x);
}

void	get_window_size(t_shell *data)
{
	struct winsize	window;

	if (ioctl(data->fd_out, TIOCGWINSZ, &window) != -1)
	{
		data->window_rows = window.ws_row;
		data->window_columns = window.ws_col;
		return ;
	}
	data->window_rows = 25;
	data->window_columns = 80;
}

void	output_enter(t_shell *data)
{
	data->input[0][data->input_len] = '\0';
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.start_cursor_x,
			data->tcaps.start_cursor_y), 1, stdin_char);
	tputs(data->tcaps.term_ce_clear_end_of_line, 1, stdin_char);
	if (data->reverse_search)
	{
		data->reverse_search = 0;
		ft_memset(data->input[0], 0, BUFFER);
		ft_strcpy(data->input[0], data->found_command);
		data->input_len = ft_strlen(data->found_command);
		ft_memset(data->found_command, 0, BUFFER);
	}
}


void	stop_raw_mode(struct termios orig_t, t_shell *data)
{
	if (data && data->raw)
	{
		if (tcsetattr(data->fd_out, TCSAFLUSH, &orig_t) == -1)
		{
			write(data->fd_err, "error in stop exit with tcsetattr\n", 29);
			exit(EXIT_FAILURE);
		}
		data->raw = 0;
	}
}

void	change_start_cursor(t_shell *data)
{
	count_input_rows(data);
	if (data->tcaps.cursor_x == 0 && data->tcaps.start_cursor_y
		+ data->input_rows > data->window_rows - 1 && !data->middle)
	{
		write(data->fd_out, " ", 1);
		data->tcaps.start_cursor_y--;
	}
	else if ((data->input_len + data->prmpt_len + data->tcaps.start_cursor_x)
		- (data->input_rows * data->window_columns) == 0
		&& data->tcaps.start_cursor_y + data->input_rows == data->window_rows)
	{
		write(data->fd_out, " ", 1);
		data->tcaps.start_cursor_y--;
		data->tcaps.cursor_y--;
		tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
				data->tcaps.cursor_y), 1, stdin_char);
	}
}

void	output_normal(t_shell *data)
{
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.start_cursor_x,
			data->tcaps.start_cursor_y), 1, stdin_char);
	tputs(data->tcaps.term_ce_clear_end_of_line, 1, stdin_char);
	if (data->reverse_search)
	{
		write(data->fd_out, data->prompt, data->prmpt_len);
		if (data->found_command[0] != '\0')
			write(data->fd_out, data->found_command, ft_strlen(data->found_command));
	}
	else
	{
		write(data->fd_out, data->prompt, data->prmpt_len);
		write(data->fd_out, data->input[0], data->input_len);
	}
	change_start_cursor(data);
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.cursor_y), 1, stdin_char);
}

void	move_end(t_shell *data)
{
	int	i;

	data->tcaps.cursor_y = data->tcaps.start_cursor_y + data->input_rows - 1;
	i = data->input_len + data->prmpt_len + data->tcaps.start_cursor_x;
	while (i > data->window_columns)
		i -= data->window_columns;
	data->tcaps.cursor_x = i;
	if (data->tcaps.cursor_x == data->window_columns)
	{
		data->tcaps.cursor_x = 0;
		data->tcaps.cursor_y++;
	}
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.cursor_y), 1, stdin_char);
}

void	move_home(t_shell *data)
{
	data->tcaps.cursor_x = data->tcaps.start_cursor_x + data->prmpt_len;
	data->tcaps.cursor_y = data->tcaps.start_cursor_y;
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.cursor_y), 1, stdin_char);
}

static void	move_left(t_shell *data)
{
	if (data->tcaps.cursor_y != data->tcaps.start_cursor_y)
	{
		if (data->tcaps.cursor_x - 1 < 0)
		{
			data->tcaps.cursor_x = data->window_columns - 1;
			data->tcaps.cursor_y--;
		}
		else
			data->tcaps.cursor_x--;
	}
	else
	{
		if (data->tcaps.cursor_x - 1 >= data->tcaps.start_cursor_x
			+ data->prmpt_len)
			data->tcaps.cursor_x--;
	}
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.cursor_y), 1, stdin_char);
}

static void	move_right(t_shell *data)
{
	count_input_rows(data);
	if ((data->tcaps.start_cursor_y != data->tcaps.cursor_y
			&& data->tcaps.cursor_x + 1 < (data->input_len + data->prmpt_len
				+ data->tcaps.start_cursor_x + 1) - ((data->tcaps.cursor_y
					- data->tcaps.start_cursor_y) * data->window_columns))
		|| (data->tcaps.start_cursor_y == data->tcaps.cursor_y
			&& data->tcaps.cursor_x + 1 < (data->input_len
				+ data->prmpt_len + 1 + data->tcaps.start_cursor_x)))
	{
		if (data->tcaps.cursor_x + 1 == data->window_columns)
		{
			if (data->tcaps.cursor_y + 1 < data->window_rows)
			{
				data->tcaps.cursor_x = 0;
				data->tcaps.cursor_y++;
			}
		}
		else
			data->tcaps.cursor_x++;
	}
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.cursor_y), 1, stdin_char);
}

void	move_cursor(t_shell *data, char c)
{
	if (data->reverse_search)
	{
		data->reverse_search = 0;
		ft_bzero(data->prompt, BUFFER + 31);
		ft_strcpy(data->prompt, "42sh> ");
		data->prmpt_len = 6;
		ft_memset(data->input[0], 0, BUFFER);
		ft_strcpy(data->input[0], data->found_command);
		data->input_len = ft_strlen(data->found_command);
		ft_memset(data->found_command, 0, BUFFER);
		tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.start_cursor_x,
				data->tcaps.start_cursor_y), 1, stdin_char);
		tputs(data->tcaps.term_ce_clear_end_of_line, 1, stdin_char);
		write(data->fd_out, data->prompt, data->prmpt_len);
		write(data->fd_out, data->input[0], data->input_len);
		change_start_cursor(data);
		data->tcaps.cursor_x = data->prmpt_len + data->input_len;
		tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.cursor_y), 1, stdin_char);
		return ;
	}
	else if (c == 'C')
		move_right(data);
	else if (c == 'D')
		move_left(data);
}

void	jump_up(t_shell *data)
{
	if (data->tcaps.cursor_y == data->tcaps.start_cursor_y)
		return ;
	else
	{
		if (data->tcaps.cursor_y - 1 != data->tcaps.start_cursor_y
			|| (data->tcaps.cursor_y - 1 == data->tcaps.start_cursor_y
				&& data->tcaps.cursor_x > data->tcaps.start_cursor_x
				+ data->prmpt_len - 1))
			data->tcaps.cursor_y--;
		tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
				data->tcaps.cursor_y), 1, stdin_char);
	}
}

void	jump_down(t_shell *data)
{
	int	end_y;
	int	end_x;

	end_y = data->tcaps.start_cursor_y + data->input_rows - 1;
	end_x = data->input_len + data->prmpt_len + data->tcaps.start_cursor_x;
	while (end_x > data->window_columns)
		end_x -= data->window_columns;
	if (data->tcaps.cursor_y + 1 < end_y || (data->tcaps.cursor_y + 1 == end_y
			&& data->tcaps.cursor_x <= end_x))
		data->tcaps.cursor_y++;
	else if (end_x == data->window_columns && data->tcaps.cursor_y + 1
		== end_y + 1 && data->tcaps.cursor_x == 0)
		data->tcaps.cursor_y++;
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.cursor_y), 1, stdin_char);
}

static int	skip_others(t_shell *data, int i)
{
	while (i >= 0)
	{
		if (!ft_isalnum(data->input[0][i]))
			i--;
		else
			break ;
	}
	return (i);
}

static int	skip_alphas(t_shell *data, int i)
{
	while (i >= 0)
	{
		if (ft_isalnum(data->input[0][i]))
			i--;
		else
			break ;
	}
	return (i);
}

static void	start_from_different_row(t_shell *data, int start, int i, int res)
{
	if (i > 0 && ft_isalnum(data->input[0][i])
		&& !ft_isalnum(data->input[0][i - 1]))
		i = skip_alphas(data, i);
	i = skip_others(data, i);
	i = skip_alphas(data, i);
	i++;
	res = start - i;
	if (data->tcaps.cursor_x - res < 0)
	{
		while (res > 0)
		{
			if (data->tcaps.cursor_x - res < 0)
			{
				data->tcaps.cursor_y--;
				res -= data->tcaps.cursor_x;
				data->tcaps.cursor_x = data->window_columns;
			}
			else
				break ;
		}
		data->tcaps.cursor_x = data->window_columns - res;
	}
	else
		data->tcaps.cursor_x -= res;
}

void	jump_left(t_shell *data, int i, int start, int res)
{
	if (data->tcaps.start_cursor_y == data->tcaps.cursor_y)
	{
		i = data->tcaps.cursor_x - data->prmpt_len
			- data->tcaps.start_cursor_x;
		if (i > 0 && ft_isalnum(data->input[0][i])
			&& !ft_isalnum(data->input[0][i - 1]))
			i = skip_alphas(data, i);
		i = skip_others(data, i);
		i = skip_alphas(data, i);
		i++;
		data->tcaps.cursor_x = i + data->prmpt_len
			+ data->tcaps.start_cursor_x;
	}
	else
	{
		i = ((data->tcaps.cursor_y - data->tcaps.start_cursor_y)
				* data->window_columns) + data->tcaps.cursor_x
			- data->prmpt_len - data->tcaps.start_cursor_x;
		start = i;
		start_from_different_row(data, start, i, res);
	}
}

static int	skip_others1(t_shell *data, int i, int len)
{
	while (i < len)
	{
		if (!ft_isalnum(data->input[0][i]))
			i++;
		else
			break ;
	}
	return (i);
}

static int	skip_alphas1(t_shell *data, int i, int len)
{
	while (i < len)
	{
		if (ft_isalnum(data->input[0][i]))
			i++;
		else
			break ;
	}
	return (i);
}

void	jump_right(t_shell *data, int i, int start, int res)
{
	i = ((data->tcaps.cursor_y - data->tcaps.start_cursor_y)
			* data->window_columns) + data->tcaps.cursor_x - data->prmpt_len
		- data->tcaps.start_cursor_x;
	start = i;
	i = skip_others1(data, i, data->input_len);
	i = skip_alphas1(data, i, data->input_len);
	res = i - start;
	if (data->tcaps.cursor_x + res > data->window_columns - 1)
	{
		while (res > 0)
		{
			if (data->tcaps.cursor_x + res > data->window_columns - 1)
			{
				data->tcaps.cursor_y++;
				res -= (data->window_columns - data->tcaps.cursor_x);
				data->tcaps.cursor_x = 0;
			}
			else
				break ;
		}
		data->tcaps.cursor_x += res;
	}
	else
		data->tcaps.cursor_x += res;
}

void	jump_words(t_shell *data, char c)
{
	if (c == 'D')
		jump_left(data, 0, 0, 0);
	else if (c == 'C')
		jump_right(data, 0, 0, 0);
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.cursor_y), 1, stdin_char);
}

int	read_escape_char(t_shell *data)
{
	char	b[4];

	ft_bzero(b, 3);
	if (read(data->fd_in, &b[0], 1) != 1 || read(data->fd_in, &b[1], 1) != 1)
		return (-1);
	if (b[0] == '[' && b[1] == 'H')
		move_home(data);
	else if (b[0] == '[' && b[1] == 'F')
		move_end(data);
	else if (b[0] == '[' && (b[1] == 'C' || b[1] == 'D'))
		move_cursor(data, b[1]);
	else
	{
		if (read(data->fd_in, &b[2], 1) != 1)
			return (-1);
		if (b[0] == '\x1b' && b[1] == '[' && b[2] == 'A')
			jump_up(data);
		else if (b[0] == '\x1b' && b[1] == '[' && b[2] == 'B')
			jump_down(data);
		else if (b[0] == '\x1b' && b[1] == '[' && (b[2] == 'C' || b[2] == 'D'))
			jump_words(data, b[2]);
	}
	return (1);
}

int	add_char(t_shell *data, char c)
{
	add_char_in_string(data, c);
	data->middle = 1;
	return (1);
}

static int	space_or_character(t_shell *data, char c)
{
	data->middle = 0;
	if (!data->reverse_search)
	{
		if ((data->tcaps.cursor_y != data->tcaps.start_cursor_y
				&& data->tcaps.cursor_x - data->prmpt_len < data->input_len
				- ((data->tcaps.cursor_y - data->tcaps.start_cursor_y)
					* data->window_columns)) || (data->tcaps.cursor_y
				== data->tcaps.start_cursor_y && data->tcaps.cursor_x
				- data->prmpt_len < data->input_len))
			return (add_char(data, c));
	}
	if (data->tcaps.cursor_x + 1 == data->window_columns)
	{
		data->tcaps.cursor_x = 0;
		if (data->tcaps.cursor_y + 1 < data->window_rows)
			data->tcaps.cursor_y++;
	}
	else
		data->tcaps.cursor_x++;
	data->input[0][data->input_len++] = c;
	data->input[0][data->input_len] = '\0';
	return (1);
}

static int	delete_char(t_shell *data)
{
	int	i;

	remove_char_in_string(data);
	i = data->tcaps.start_cursor_y + data->input_rows;
	while (i > data->tcaps.start_cursor_y)
	{
		tputs(tgoto(data->tcaps.term_cm_cursor_pos, 0, i--), 1, stdin_char);
		tputs(data->tcaps.term_ce_clear_end_of_line, 1, stdin_char);
	}
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.start_cursor_x,
			data->tcaps.start_cursor_y), 1, stdin_char);
	tputs(data->tcaps.term_ce_clear_end_of_line, 1, stdin_char);
	write(data->fd_out, data->prompt, data->prmpt_len);
	write(data->fd_out, data->input[0], data->input_len);
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.cursor_y), 1, stdin_char);
	return (-1);
}

int	check_delete_condition(t_shell *data)
{
	if (!data->reverse_search)
	{
		if (data->input_len > 0 && ((data->tcaps.cursor_y
					== data->tcaps.start_cursor_y && data->tcaps.cursor_x
					<= data->input_len + data->prmpt_len
					+ data->tcaps.start_cursor_x && data->tcaps.cursor_x
					< data->window_columns && data->tcaps.cursor_x - 1
					> data->prmpt_len - 1) || (data->tcaps.cursor_y
					> data->tcaps.start_cursor_y && data->tcaps.cursor_x
					<= data->input_len + data->prmpt_len
					+ data->tcaps.start_cursor_x - (data->window_columns
						* (data->tcaps.cursor_y - data->tcaps.start_cursor_y)))))
			return (delete_char(data));
	}
	else
	{
		if (data->input_len - 1 >= 0)
		{
			data->reverse_delete = 1;
			data->input[0][--data->input_len] = '\0';
			return (1);
		}
	}
	return (-1);
}

int	recognise_input_char(t_shell *data, char c)
{
	char	c2;

	c2 = 0;
	if (c == '\x1b')
		read_escape_char(data);
	if (c == CTRL_D && data->input_len == 0)
	{
		stop_raw_mode(data->orig_t, data);
		tputs(data->tcaps.term_te_stop, 1, stdin_char);
		exit (0);
	}
	if (c == DELETE)
		return (check_delete_condition(data));
	else if (c == SPACE || (c > 32 && c < 127))
		return (space_or_character(data, c));
	return (-1);
}

int	read_loop(t_shell *data, int x)
{
	char	c;

	c = '\0';
	x = read(data->fd_in, &c, 1);
	while (x > -1)
	{
		if (recognise_input_char(data, c) == 1)
		{
			output_normal(data);
		}
		else if (c == ENTER || data->input_len == BUFFER + 1)
		{
			if (c == ENTER)
				output_enter(data);
			return (-2);
		}
		c = '\0';
		x = read(0, &c, 1);
	}
	return (x);
}

void	get_cursor_position(t_shell *data)
{
	char	buf[15];
	int		i;
	int		ret;

	i = 0;
	ft_bzero(buf, 15);
	write(1, "\033[6n", 4);
	ret = read(0, &buf[i++], 1);
	while (ret && buf[i - 1] != 'R' && i < 15)
		ret = read(0, &buf[i++], 1);
	data->tcaps.cursor_y = ft_atoi(buf + 2);
	data->tcaps.cursor_x = ft_atoi(buf + 2
			+ ft_count_digit(data->tcaps.cursor_y) + 1);
}

void	back_to_raw_mode(struct termios raw_t, t_shell *data)
{
	if (tcsetattr(data->fd_out, TCSAFLUSH, &raw_t) == -1)
	{
		if (data->pipe_err == 0)
			write(data->fd_err, "error in back exit with tcsetattr\n", 29);
		else
			data->pipe_err = 0;
		exit(EXIT_FAILURE);
	}
	data->raw = 1;
}

void	enter_raw_mode(t_shell *data)
{
	if (tcgetattr(data->fd_in, &data->orig_t) == -1
		|| tcgetattr(data->fd_in, &data->raw_t) == -1)
	{
		if (data->pipe_err == 0)
			write(data->fd_err, "error with tcgetattr\n", 21);
		else
			data->pipe_err = 0;
		exit(EXIT_FAILURE);
	}
	data->raw_t.c_iflag &= ~(ICRNL | IXON);
	data->raw_t.c_oflag &= ~(OPOST);
	data->raw_t.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	data->raw_t.c_cc[VMIN] = 0;
	data->raw_t.c_cc[VTIME] = 1;
	data->raw = 1;
	return ;
}

void	set_reading_variables(t_shell *data)
{
	ft_bzero(data->prompt, BUFFER + 31);
	ft_strcpy(data->prompt, "42sh> ");
	data->prmpt_len = 6;
	enter_raw_mode(data);
	back_to_raw_mode(data->raw_t, data);
	get_cursor_position(data);
	data->tcaps.cursor_x--;
	data->tcaps.cursor_y--;
	data->tcaps.start_cursor_y = data->tcaps.cursor_y;
	data->tcaps.start_cursor_x = data->tcaps.cursor_x;
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.start_cursor_x,
			data->tcaps.start_cursor_y), 1, stdin_char);
	tputs(data->tcaps.term_ce_clear_end_of_line, 1, stdin_char);
	write(data->fd_out, data->prompt, data->prmpt_len);
	data->tcaps.cursor_x += data->prmpt_len;
	tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->tcaps.cursor_x,
			data->tcaps.start_cursor_y), 1, stdin_char);
	data->input_len = 0;
	ft_bzero(data->input[0], BUFFER);
	ft_bzero(data->tmp_str, BUFFER);
}

int	read_input_and_check_quotes(t_shell *data)
{
	int	ret;

	ret = 1;
	set_reading_variables(data);
	while (ret >= 0)
		ret = read_loop(data, ret);
	if (ret != -2)
	{
		tputs(tgoto(data->tcaps.term_cm_cursor_pos, data->prmpt_len,
				data->tcaps.cursor_y), 1, stdin_char);
		tputs(data->tcaps.term_ce_clear_end_of_line, 1, stdin_char);
	}
	if (ret == 0)
	{
		data->input[data->input_len][0] = '\0';
		write(data->fd_out, &data->input, data->input_len);
		stop_raw_mode(data->orig_t, data);
		exit (0);
	}
	// if (write_and_history(data) == -1)
	// 	return (-1);
	// if (check_amount_of_quotes(data->input[0], 0, '\0') == -1)
	// 	return (loop_more_quotes(data));
	stop_raw_mode(data->orig_t, data);
	return (1);
}

static void	init_data(t_shell *data)
{
	int	i;

	i = 0;
	data->pid_check = 0;
	data->input_len = 0;
	data->history_line = -1;
	data->history_out = 0;
	data->pid_i = -1;
	data->child = -1;
	while (i < HISTORY_LEN)
		ft_memset(&data->history[i++], 0, BUFFER);
}

// void	while_loop_input(t_shell *data)
// {
// 	int				i;
// 	int				ii;

// 	init_data(data);
// 	read_history_from_file(data);
// 	while (1)
// 	{
// 		i = 0;
// 		ii = 0;
// 		get_window_size(data);
// 		if (read_input_and_check_quotes(data) == 1)
// 		{
// 			data->pid_check = 1;
// 			check_and_clear_input(data, 0, 0);
// 			while (data->input[i][0] != '\0')
// 				ft_memset(&data->input[i], 0, BUFFER);
// 		}
// 		else
// 			ft_memset(&data->input[0], 0, BUFFER);
// 	}
// }

void	run_shell(t_shell *data)
{
	t_ast	**tree;
	int		i;
	int		ii;

	init_data(data);
	ft_memset(&tree, 0, sizeof(t_ast *));
	while (TRUE)
	{
		// signal_listen();
		i = 0;
		ii = 0;
		get_window_size(data);
		if (read_input_and_check_quotes(data) == 1)
		{
				ft_putchar_fd('\n', STDOUT_FILENO);
				// history_runtime(data);
				tree = ast_constructor(parser(data));
				if (tree != NULL)
					exec_tree(tree, data);
				data->pid_check = 1;
				while (data->input[i][0] != '\0')
					ft_memset(&data->input[i], 0, BUFFER);
		}
		else
			ft_memset(&data->input[0], 0, BUFFER);
	}
			// cmd_line_reset(data, &shell->window);
			// cursor_find(shell, &shell->window);
			// cursor_load(&shell->window, -1);
			// init_in_out_err(shell->tty);
}
