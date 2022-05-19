/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:54:42 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/18 21:55:07 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

//static int message = 0;

void    handler()
{
    write(1, "signal from server\n", 19);
}

void    send_bits(int pid, unsigned char c)
{
    int     i;

    i = 0;
    while (i < 8)
    {
        if (c & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(500);
        c = c >> 1;
        i++;
    }
}

int main(int argc, char *argv[])
{
    int     i;
    int     pid;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (argv[2][i])
        {
            send_bits(pid, argv[2][i]);
            i++;
        }
        send_bits(pid, argv[2][i]);
        signal(SIGUSR1, handler);
        /*if (message == 1)
            write(1, "signal from server\n", 19);*/
        while (1)
            pause();
    }
    return (0);
}
