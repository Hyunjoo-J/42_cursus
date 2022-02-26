/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:33 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/26 23:04:14 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	handler(int num)
{
	(void) num;
}

struct sigaction	init(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_handler = &handler;
	return (act);
}

int	error_check(int argc)
{
	if (argc != 3)
	{
		ft_putstr_fd("usage : ./client <server pid> \"<message>\"\n", 1);
		exit (0);
	}
	return (0);
}

void	send(char *argv, unsigned int bit, int pid)
{
	if (*argv & bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	unsigned long int	len;
	unsigned int		bit;
	int					i;

	act = init();
	sigaction(SIGUSR1, &act, 0);
	error_check(argc);
	len = ft_strlen(argv[2]) + 1;
	while (len--)
	{
		i = 0;
		bit = 0b10000000;
		while (i++ < 8)
		{
			send(argv[2], bit, ft_atoi(argv[1]));
			bit >>= 1;
			pause();
			usleep(10);
		}
		argv[2]++;
		if (len == 0)
			ft_putstr_fd("Message arrived successfully!\n", 1);
	}
	return (0);
}
