/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:16:00 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/11 22:16:20 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_putchar(char c, int *l);
int		ft_putstr(char *s, int *l);
void	ft_putnbr(int n, int *l);
void	ft_print_base(unsigned long n, char *base, int size, int *l);
#endif
