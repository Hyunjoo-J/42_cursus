/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:17:33 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/23 19:17:46 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send(pid_t pid, int num)
{
	if (num == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("Fail to send a signal\n", 1);
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("Fail to send a signal\n", 1);
			exit(0);
		}
	}
	usleep(100);

}

void	bit_cal(pid_t pid, int num)
{
	if (num != 0)
	{
		bit_cal(pid, num / 2);
		send(pid, num % 2);
	}
}

void	count_pos(pid_t pid, char c)
{
	int	num;
	int	pos;
	int i;

	num = (int)c;
	pos = 1;
	i = 0;
	while (num != 1 || num != 0)
	{
		num = num / 2;
		pos++;
	}
	while (i < 8 - pos)
	{
		send(pid, 0);
		i++;
	}
	num = (int)c;
	bit_cal(pid, num);
}

void	send_end(pid_t	pid)
{
	int	i;
	char	c;

	c = '\0';
	i = 0;
	while(i++ < 8)
	{
		if (c % 2 == 1)
			send(pid, 1);
		else
			send(pid, 0);
		c >>= 1;
		usleep(100);
	}
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("usage : ./client <server pid> <message>\n", 1);
		return (0);
	}
	else if (100 < argv[1] && argv[1] < 99999)
	{
		ft_putstr_fd("Wrong pid range!");
		return(0);
	}
	while (argv[2][i]
	{
		count_pos(argv[1], argv[2][i]);
		i++;
	}
	send_end(argv[1]);
	return (0);
}