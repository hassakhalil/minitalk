/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:24:24 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/20 06:17:58 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static unsigned char	c;
	static int				bits;
	static int				n;

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
		write(1, &c, 1);
		bits = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
