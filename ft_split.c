/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 09:15:49 by rcollas           #+#    #+#             */
/*   Updated: 2021/05/21 14:15:28 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static int	ft_strlen(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(str[i], charset))
		i++;
	return (i);
}

static int	ft_count_words(char const *str, char charset)
{
	int	words_count;
	int	is_word;

	words_count = 0;
	is_word = 1;
	while (*str)
	{
		if (is_word && !is_charset(*str, charset))
		{
			words_count++;
			is_word = 0;
		}
		else if (is_charset(*str, charset))
			is_word = 1;
		str++;
	}
	return (words_count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		j;
	int		i;
	int		words;

	words = ft_count_words(s, c);
	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(split) * ft_count_words(s, c) + 1);
	if (!split)
		return (NULL);
	while (i < words)
	{
		while (is_charset(*s, c))
			s++;
		split[i] = (char *)malloc(sizeof(*split) * ft_strlen(s, c) + 1);
		if (!split[i])
			return (NULL);
		while (!is_charset(*s, c))
		{
			split[i][j++] = *s;
			s++;
		}
		split[i][j] = 0;
		j = 0;
		i++;
	}
	split[i] = 0;
	return (split);
}