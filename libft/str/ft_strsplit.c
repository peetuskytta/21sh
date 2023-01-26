/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:07:07 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/25 14:12:19 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (*s)
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*make_word(char const *s, char c, size_t i)
{
	int		len;
	char	*word;

	len = i;
	while (s[len] != c && s[len] != '\0')
		len++;
	word = ft_strsub(s, i, (len - i));
	if (!word)
		free(word);
	return (word);
}

static char	**split_string(char const *s, char c, size_t count)
{
	size_t		j;
	size_t		i;
	char		**words;

	i = 0;
	j = 0;
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	while (s[i] && j < count)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			words[j] = make_word(s, c, i);
			i = i + ft_strlen(words[j]);
			i++;
		}
		j++;
	}
	words[j] = NULL;
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**words;

	if (!s)
		return (NULL);
	count = ft_countwords(s, c);
	words = split_string(s, c, count);
	if (!words)
		ft_arr_free((void *)&words);
	return (words);
}
