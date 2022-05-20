/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:26:32 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/27 14:28:00 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_bits(int pid, unsigned char c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (c & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        c = c >> 1;
        i++;
        usleep(100);
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
    }
    return (0);
}
