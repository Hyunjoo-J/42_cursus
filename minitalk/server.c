/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:30:53 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/22 21:48:10 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
	pid_t	server_pid;
	struct sigaction	act;

	server_pid = getpid();
	ft_putstr_fd("Server pid : ", 1);
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
	act.sa_flags = ;
	act.sa_mask
	return (0);
}