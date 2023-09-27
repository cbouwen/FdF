/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:30:57 by cbouwen           #+#    #+#             */
/*   Updated: 2023/05/15 13:42:30 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 10)
	{
		count += ft_int(num / 10);
		count += ft_int(num % 10);
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}

static unsigned int	neg(int num)
{
	return (-(unsigned int)num);
}

int	handle_int(int num)
{
	int				count;
	unsigned int	nb;

	count = 0;
	if (num == 0)
	{
		count += ft_putchar(num + '0');
		return (count);
	}
	else if (num < 0)
	{
		nb = neg(num);
		count += ft_putchar('-');
	}
	else
		nb = num;
	count += ft_int(nb);
	return (count);
}

int	ft_put_unbr_base(unsigned int num, const char d)
{
	unsigned int	i;
	int				count;

	i = 10;
	count = 0;
	if (d == 'x' || d == 'X')
		i = 16;
	if (num >= i)
	{
		count += ft_put_unbr_base(num / i, d);
		count += ft_put_unbr_base(num % i, d);
	}
	else
	{
		if (num <= 9)
			count += ft_putchar(num + '0');
		else
		{
			if (d == 'x')
				count += ft_putchar(num - 10 + 'a');
			if (d == 'X')
				count += ft_putchar(num - 10 + 'A');
		}
	}
	return (count);
}

int	put_unbr_base(unsigned int num, const char d)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		count += ft_putchar(num + '0');
		return (count);
	}
	count += ft_put_unbr_base(num, d);
	return (count);
}
