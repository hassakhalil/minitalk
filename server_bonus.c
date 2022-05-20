/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:53:34 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/20 06:22:21 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bits;
	static int				n;

	(void)context;
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
			kill(info->si_pid, SIGUSR2);
		else
			write(1, &c, 1);
		bits = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

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
