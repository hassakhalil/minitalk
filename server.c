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

char    *s = NULL;

void    handler1()
{
    //s = ft_strjoin(s, "0");
    printf("0\n");
}

void    handler2()
{
    //s = ft_strjoin(s, "1");
    printf("1\n");
}

int convert_to_decimal(char *s)
{
    int dec_value = 0;
    int base = 1;
    int len = 32;
    int i = len -1;

    while (i >= 0)
    {
        if (s[i] == '1')
            dec_value += base;
        base  = base * 2;
        i--;
    }
    return (0);
}

int main()
{
	pid_t   pid;

    pid = getgid();
    printf("%d\n", pid);
    pause();
   // printf("hello its safe above");
    signal(SIGUSR1, handler1);
   // printf("hello its safe above");
    signal(SIGUSR2, handler2);
    //printf("hello its safe above");
    //printf("%c", convert_to_decimal(s));
    return (0);

}
