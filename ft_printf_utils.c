/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:11:08 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/11 22:12:54 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_base(unsigned long nb, char *base, int size, int *l)
{
	if (nb >= (unsigned long)size)
		ft_print_base((nb / size), base, size, l);
	ft_putchar(base[nb % size], l);
}

void	ft_putchar(char c, int *l)
{
	write(1, &c, 1);
	(*l)++;
}

void	ft_putnbr(int n, int *l)
{
	char	c;
	long	x;

	x = n;
	if (x < 0)
	{
		write(1, "-", 1);
		(*l)++;
		x = x * (-1);
	}
	if (x > 9)
	{
		ft_putnbr(x / 10, l);
		ft_putnbr(x % 10, l);
	}
	else
	{
		c = x + '0';
		write(1, &c, 1);
		(*l)++;
	}
}

int	ft_putstr(char *s, int *l)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		(*l)++;
	}
	return (1);
}
