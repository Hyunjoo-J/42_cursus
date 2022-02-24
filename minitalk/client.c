/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:33 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/24 21:13:09 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int num, unsigned int *bit)
{
	(void) num;
	&bit >>= 1;
}

struct sigaction	init(unsigned long int *len, char **argv)
{
	struct sigaction	act;

	*len = (ft_strlen(argv[2]) + 1);
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

int	main(int argc, char **argv)
{
	struct sigaction	act;
	unsigned long int	len;
	unsigned int		bit;

	error_check(argc);
	act = init(&len, argv);
	sigaction(SIGUSR1, &act, 0);
	while (len--)
	{
		bit = 0b10000000;
		while (bit)
		{
			if (*argv[2] & bit)
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			pause();
			usleep(50);
		}
		argv[2]++;
	}
ㅑ	return (0);
}
