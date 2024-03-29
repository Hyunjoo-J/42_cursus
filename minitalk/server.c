/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:04 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/25 03:25:41 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler(int signo, siginfo_t *info, void *context)
{
	(void) context;
	if (signo == SIGUSR1)
		g_sig.symbol += g_sig.bit;
	g_sig.bit >>= 1;
	if (!g_sig.bit)
	{
		if (!g_sig.symbol)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(g_sig.symbol, 1);
		g_sig.bit = 0b10000000;
		g_sig.symbol = 0;
	}
	usleep(10);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	g_sig.bit = 0b10000000;
	g_sig.symbol = 0;
	g_sig.pid = getpid();
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &act, 0) == -1 || sigaction(SIGUSR2, &act, 0) == -1)
	{
		ft_putstr_fd("signal error\n", 1);
		return (0);
	}
	ft_putstr_fd("Server pid : ", 1);
	ft_putnbr_fd(g_sig.pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
}
