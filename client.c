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

char    *convert_to_binary(int n)
{
    char    *s;
    int     i;
    int     k;
    int     j = 0;

    s = malloc(33 * sizeof(char ));
    i = 31;
    while (i >= 0)
    {
        k = n >> i;
        if (k & 1)
            s[j] = '1';
        else
            s[j] = '0';
        j++;
        i--;
    }
    s[j] = 0;
    return (s);
}

int main(int argc, char *argv[])
{
    int     i;
    int     j;
    char    *s;
    char    c;

    i = 0;
    if (argc == 3)
    {
        while (argv[2][i])
        {
            c = argv[2][i];
            s = convert_to_binary(ft_atoi(&c));
            printf("%s\n", s);
            j = 0;
            while(s[j])
            {
                if (s[j] == '0')
                    kill(ft_atoi(argv[1]), SIGUSR1);
                else
                    kill(ft_atoi(argv[1]), SIGUSR2);
                sleep(1);
                j++;
            }
            if (s)
                free(s);
            i++;
        }
    }
    return (0);
}
