/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:24:07 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/13 14:21:11 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tdest;
	unsigned char	*tsrc;

	tdest = (unsigned char *)dest;
	tsrc = (unsigned char *)src;
	if (tdest == tsrc || n == 0)
		return (dest);
	if (tdest < tsrc)
		while (n--)
			*tdest++ = *tsrc++;
	if (tdest > tsrc)
		while (n--)
			tdest[n] = tsrc[n];
	return (dest);
}
