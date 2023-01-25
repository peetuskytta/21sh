/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: zraunio <zraunio@student.hive.fi>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/15 15:22:42 by pskytta		   #+#	#+#			 */
/*   Updated: 2023/01/25 13:30:13 by zraunio		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../incl/libft.h"
/*
**This function finds the line, places it in *line, then duplicates the
**rest into a temp pointer. it frees the original pointer, then points it to
**temp, a.k.a. the rest of the fd not yet read. if EOF is reached, we del s[fd]
*/

static int	ft_find_line(char **s, int fd, int i, char **line)
{
	int		j;
	char	*tmp;

	j = 0;
	while (s[fd][j] != '\n' && s[fd][j] != '\0')
		j++;
	if (s[fd][j] == '\n')
	{
		*line = ft_strsub(s[fd], 0, j);
		tmp = ft_strdup(&(s[fd][j + 1]));
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][j] == '\0')
	{
		if (i == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[FD_SIZE];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			i;

	i = read(fd, buf, BUFF_SIZE);
	while (i > 0)
	{
		buf[i] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		ft_strdel(&s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n'))
			break ;
		i = read(fd, buf, BUFF_SIZE);
	}
	if (i < 0)
		return (-1);
	if ((i == 0 && s[fd] == NULL) || s[fd] == NULL)
		return (0);
	else
		return (ft_find_line(s, fd, i, line));
}
