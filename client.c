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

int ft_size(int n)
{
    int i;
    i = 0;
    while (n)
    {
        n = n / 2;
        i++;
    }
    return (i);
}

char    *convert_to_binary(int n)
{
    char    *s;
    int     i;

    s = malloc(ft_size(n) * sizeof(char));
    i = 0;
    while (n)
    {
        s[i] = (n % 2) + 48;
        n = n / 2;
        i++;
    }
    s[i] = 0;
    return (s);
}

int main(int argc, char *argv[])
{
    int     i;
    int     j;
    char    *s;

    i = 0;
    if (argc == 3)
    {
        while (argv[2][i])
        {
            s = convert_to_binary(ft_atoi(&argv[2][i]));
            j = 0;
            while(s[j])
            {
                if (s[j] == '0')
                    kill(ft_atoi(argv[1]), SIGUSR1);
                else
                    kill(ft_atoi(argv[1]), SIGUSR2);
                j++;
            }
            if (s)
                free(s);
            i++;
        }
    }
    return (0);
}
