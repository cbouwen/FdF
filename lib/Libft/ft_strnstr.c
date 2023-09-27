/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:33:33 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/13 15:26:41 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && (i + little_len <= len))
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
