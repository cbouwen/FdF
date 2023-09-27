/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:08:27 by cbouwen           #+#    #+#             */
/*   Updated: 2023/05/15 13:39:40 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(uintptr_t ptrA)
{
	int	count;

	count = 0;
	if (ptrA >= 16)
	{
		count += ft_put_ptr(ptrA / 16);
		count += ft_put_ptr(ptrA % 16);
	}
	else
	{
		if (ptrA <= 9)
			count += ft_putchar(ptrA + '0');
		else
			count += ft_putchar(ptrA - 10 + 'a');
	}
	return (count);
}

int	handle_p(uintptr_t ptrA)
{
	int	count;

	count = 0;
	if (ptrA == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_put_ptr(ptrA);
	return (count);
}
