/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:57:11 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/14 11:31:24 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_module(int n)
{
	if (n < 0)
		return (-(unsigned int)n);
	return (n);
}

char	*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	int				i;
	unsigned int	num;

	len = ft_count(n);
	i = len;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	if (n == 0)
		s[0] = 48;
	if (n < 0)
		s[0] = '-';
	num = ft_module(n);
	while (num > 0)
	{
		s[--len] = num % 10 + 48;
		num = num / 10;
	}
	s[i] = '\0';
	return (s);
}
