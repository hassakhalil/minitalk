/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:24:24 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/27 14:28:47 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char    *s;

void    handler1()
{
    s = ft_strjoin(s, "0");
}

void    handler2()
{
    s = ft_strjoin(s, "1");
}

int convert_to_decimal(char *s)
{
    return (0);
}

int main()
{
	pid_t   pid;

    pid = getgid();
    ft_printf("%d\n", pid);
    s = 0;
    signal(SIGUSR1, handler1);
    signal(SIGUSR2, handler2);
    ft_printf("%c", convert_to_decimal(s));
    return (0);

}
