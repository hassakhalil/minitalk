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
#include <string.h>

void    handler(int sig)
{
    static unsigned char c = 0;
    static int bits = 0;
    static int n = 0;   

    if (bits == 0)
    {
        bits = 0;
        c = 0;
        n = 1;
    }
    if (sig == SIGUSR2)
        c = c | n;
    n = n << 1;
    bits++;
    if (bits == 8)
    {
        write(1, &c, 1);
        bits = 0;
    }
}

int main()
{
	int   pid;

    pid = getpid();
    ft_putnbr_fd(pid, 1);
    write(1, "\n", 1);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
        pause();
    return (0);
}
