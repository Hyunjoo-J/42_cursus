/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:59:12 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/05/31 04:24:26 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

void	ft_print_error(int fd, char *cmd, char *arg, char *msg)
{
	write(fd, "bash: ", 6);
	if (cmd != 0)
	{
		write(fd, cmd, ft_strlen(cmd));
		write(fd, ": ", 2);
	}
	if (arg != 0)
	{
		write(fd, arg, ft_strlen(arg));
		write(fd, ": ", 2);
	}
	write(fd, msg, ft_strlen(msg));
	write(fd, "\n", 1);
}

void	ft_error(int exit_status)
{
	struct termios	new_term;

	tcgetattr(0, &new_term);
	new_term.c_lflag |= (ECHOCTL);
	tcsetattr(0, TCSANOW, &new_term);
	ft_reset_uni();
	free_env();
	exit(exit_status);
}