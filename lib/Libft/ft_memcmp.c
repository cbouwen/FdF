/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:38:07 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/13 14:54:39 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp;
	unsigned char	*buff;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	temp = (unsigned char *)s1;
	buff = (unsigned char *)s2;
	while (i < n)
	{
		if (temp[i] != buff[i])
			return (temp[i] - buff[i]);
		i++;
	}
	return (0);
}
