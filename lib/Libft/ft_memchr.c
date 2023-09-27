/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:23:01 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/13 14:43:26 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*t;
	unsigned char		p;

	t = (unsigned char *)s;
	p = (unsigned char)c;
	while (n--)
	{
		if (*t == p)
			return ((void *)t);
		t++;
	}
	return (0);
}
