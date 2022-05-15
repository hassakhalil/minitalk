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
#include <stdio.h>


int main(int argc, char *argv[])
{
    int     i;
    int     j;

    i = 0;
    if (argc == 3)
    {
        while (argv[2][i])
        {
            j = 8;
            while (j)
            {
                if (argv[2][i] & 1)
                    kill(ft_atoi(argv[1]), SIGUSR2);
                else
                    kill(ft_atoi(argv[1]), SIGUSR1);
                j++;
                argv[2][i] = argv[2][i] >> 1;
            }
            i++;
        }
    }
    return (0);
}
