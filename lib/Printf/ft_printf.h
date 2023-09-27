/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:25:51 by cbouwen           #+#    #+#             */
/*   Updated: 2023/05/15 13:48:00 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstring(char *s);
int	parser(va_list args, const char c);
int	ft_int(unsigned int num);
int	handle_int(int num);
int	ft_put_unbr_base(unsigned int num, const char d);
int	put_unbr_base(unsigned int num, const char d);
int	ft_put_ptr(uintptr_t ptrA);
int	handle_p(uintptr_t ptrA);

#endif
