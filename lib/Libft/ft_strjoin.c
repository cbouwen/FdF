/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:32:08 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/12 16:37:56 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counter(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	slen1;
	size_t	slen2;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	slen1 = counter(s1);
	slen2 = counter(s2);
	s3 = (char *)malloc((slen1 + slen2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i + j] = s2[j];
	s3[slen1 + slen2] = '\0';
	return (s3);
}
