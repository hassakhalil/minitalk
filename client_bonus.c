/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:54:42 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/19 20:48:53 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void    print_message(int sig)
{
	(void)sig;
    write(1, "received signal from server\n", 29);
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

    signal(SIGUSR2, print_message);
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
    }
    return (0);
}
