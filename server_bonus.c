/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:53:34 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/18 21:54:10 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int  signalpid = 0;

void    handler(int sig, siginfo_t *info, void *context)
{
    static unsigned char c = 0;
    static int bits = 0;
    static int n = 0;
    void    **x;

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
        if (c == 0)
        {
            printf("ssent     fefwefwefwefwef    \n");
            kill(signalpid, SIGUSR1);
            usleep(500);
        }
        else
            write(1, &c, 1);
        bits = 0;
    }
    x = &context;
    signalpid = info->si_pid;
}

int main()
{
	int    pid;
    struct sigaction    sa;
    

    pid = getpid();
    ft_putnbr_fd(pid, 1);
    write(1, "\n", 1);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}