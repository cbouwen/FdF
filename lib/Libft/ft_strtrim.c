/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:51:38 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/13 14:06:31 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *set, const char s)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (ft_check(set, *s1) == 0)
			break ;
		s1++;
	}
	size = ft_strlen(s1);
	while (size > 0)
	{
		if (ft_check(set, s1[size - 1]) == 0)
			break ;
		size--;
	}
	s2 = (char *)malloc(sizeof(char) * size + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, size + 1);
	return (s2);
}
