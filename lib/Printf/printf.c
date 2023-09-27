/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:59:15 by cbouwen           #+#    #+#             */
/*   Updated: 2023/05/15 13:05:05 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstring(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	parser(va_list args, const char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (c == 's')
		i = ft_putstring(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		i = handle_int(va_arg(args, int));
	else if (c == 'x' || c == 'X' || c == 'u')
		i = put_unbr_base(va_arg(args, unsigned int), c);
	else if (c == 'p')
		i = handle_p((uintptr_t)va_arg(args, void *));
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += parser(args, format[++i]);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
