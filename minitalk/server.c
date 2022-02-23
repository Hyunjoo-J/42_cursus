/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:04 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/23 19:17:47 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "server.h"

void	handler(int signo, siginfo_t *info, void *context)
{
}

int main()
{
	pid_t	server_pid;
	struct sigaction	act;

	server_pid = getpid();
	ft_putstr_fd("Server pid : ", 1);
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
	{
		write(1, "ERROR\n", 6);
		exit(0);
	}
	if (sigaction(SIGUSR2, &act, NULL) != 0)
	{
		write(1, "ERROR\n", 6);
		exit(0);
	}
	return (0);
}