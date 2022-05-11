/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:13:51 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/11 22:13:59 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conversions(const char *s, va_list ptr, int i, int *l)
{
	if (s[i] == 'c')
		ft_putchar(va_arg(ptr, int), l);
	else if (s[i] == 's')
	{
		if (!ft_putstr(va_arg(ptr, char *), l))
			ft_putstr("(null)", l);
	}
	else if (s[i] == 'p')
	{
		ft_putstr("0x", l);
		ft_print_base(va_arg(ptr, unsigned long), "0123456789abcdef", 16, l);
	}
	else if (s[i] == 'd' || s[i] == 'i')
		ft_putnbr(va_arg(ptr, int), l);
	else if (s[i] == 'u')
		ft_print_base(va_arg(ptr, unsigned int), "0123456789", 10, l);
	else if (s[i] == 'x')
		ft_print_base(va_arg(ptr, unsigned int), "0123456789abcdef", 16, l);
	else if (s[i] == 'X')
		ft_print_base(va_arg(ptr, unsigned int), "0123456789ABCDEF", 16, l);
	else
		ft_putchar(s[i], l);
}

int	ft_arguments_count(const char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (s[i] == '%')
	{
		n++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == '%' && s[i - 1] != '%')
			n++;
		i++;
	}
	return (n);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		i;
	int		n;
	int		l;

	i = 0;
	l = 0;
	n = ft_arguments_count(s);
	if (!n)
	{
		ft_putstr((char *)s, &l);
		return (l);
	}
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] == '%')
			ft_printf_conversions(s, ptr, ++i, &l);
		else
			ft_putchar(s[i], &l);
		i++;
	}
	va_end(ptr);
	return (l);
}
