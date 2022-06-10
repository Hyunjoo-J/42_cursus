/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:37:46 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/09 23:37:47 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	func(char *limit, char *input, int fd)
{
	if (ft_strcmp(limit, input) == 0)
	{
		free(input);
		return (0);
	}
	if (input[0] != '\0')
	{
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
	}
	free(input);
	return (1);
}

<<<<<<< HEAD
int	here_doc(char *limit) //ctrl^C누를 떄 끝나야하는뎅.... ctrl^D 누르면 끝나넹...?
{
	char	*input;
	int		fd[2];
	//pid_t	pid;

	if (pipe(fd) == -1)
		return (-1);
	while (1)
	{
		input = readline("> ");
		if (!input) //고민
		{
			//printf("minishell: warning: here-document at line 299 delimited by end-of-file\n");//error_mssg
			break ;
		}
		else
		{
			if (!func(limit, input, fd[1]))
				break ;
		}
	}
	/*pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			//signal(SIGINT, ft_here_doc_sig);
			input = readline("> ");
			if (!input) //고민
			{
				printf("minishell: warning: here-document at line 299 delimited by end-of-file\n");//error_mssg
				break ;
			}
			else
			{
				if (!func(limit, input, fd[1]))
					break ;
			}
		}
	}*/
	close(fd[1]);
	//waitpid(pid, 0, 0);
=======
int	here_doc(char *limit, t_info *info) //ctrl^C누를 떄 끝나야하는뎅.... ctrl^D 누르면 끝나넹...?
{
	char	*input;
	int		fd[2];
	int		status;
	pid_t	pid;

	if (pipe(fd) == -1)
		free_exit(info);
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		free_exit(info);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			signal(SIGINT, ft_here_doc_sig);
			input = readline("> ");
			if (!input) //고민
				break ;
			else
			{
				if (!func(limit, input, fd[1]))
					break ;
			}
		}
		exit(0);
	}
	signal(SIGINT, ft_here_doc_sig_parent);
	close(fd[1]);
	waitpid(pid, &status, 0);
	g_exit_num = (status & 0xff00) >> 8;
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
	return (fd[0]);
}