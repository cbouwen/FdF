/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:28:38 by cbouwen           #+#    #+#             */
/*   Updated: 2023/05/08 12:09:00 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **s2, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(s2[i]);
		i++;
	}
	free(s2);
	return (0);
}

static char	*put_word(char *word, int word_len, char const *s, int i)
{
	int	t;

	t = 0;
	while (0 < word_len)
	{
		word[t] = s[i - word_len];
		t++;
		word_len--;
	}
	word[t] = '\0';
	return (word);
}

static char	**split_words(char const *s, char c, char **s2, int words)
{
	int	i;
	int	count;
	int	word_len;

	i = 0;
	count = 0;
	word_len = 0;
	while (count < words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[count] = (char *)malloc(sizeof(char) * word_len + 1);
		if (!s2[count])
			return (ft_free(s2, count));
		put_word(s2[count], word_len, s, i);
		word_len = 0;
		count++;
	}
	s2[count] = 0;
	return (s2);
}

static int	word_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**s2;

	words = word_count(s, c);
	s2 = (char **)malloc(sizeof(char *) * (words + 1));
	if (!s2)
		return (NULL);
	s2 = split_words(s, c, s2, words);
	return (s2);
}
