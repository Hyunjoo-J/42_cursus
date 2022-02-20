/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:30:53 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/20 22:37:37 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
	pid_t	server_pid;
	struct sigaction	act;

	server_pid = getpid();
	ft_putstr_fd("Server pid : ", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putstr_fd("\n", 1);
	act.sa_flags = ;
	act.sa_
	return (0);
}