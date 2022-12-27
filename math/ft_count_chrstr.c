/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:35:18 by pskytta           #+#    #+#             */
/*   Updated: 2022/10/26 13:57:16 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This functions counts the amount of times a character specificied in
**	the parameter c occurs in the string given as a parameter.
**	Returns the amount of characters found in the string.
*/
int	ft_count_chrstr(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == c)
			count++;
	}
	return (count);
}
