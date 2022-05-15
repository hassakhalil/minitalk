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
#include <stdio.h>

void    handler(int sig)
{
    static char c;
    static int bits;
    static int n;   

    if (bits == 0)
    {
        c = '0';
        n = 1;
    }
    if (sig == SIGUSR2)
        c = c | n;
    n = n << 1;
    bits++;
    if (bits == 8)
    {
        printf("%c", c);
        bits = 0;
    }
}

int main()
{
	pid_t   pid;

    pid = getpid();
    printf("%d\n", pid);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
        pause();
    return (0);

}
