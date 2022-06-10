/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:39:01 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/10 01:40:26 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	free_pid(t_info *info) //25줄 확인!!
{
	int	i;
	int	status;
<<<<<<< HEAD

	i = 0;
	while (i < info->have_pipe)
=======
	int	e_num;

	i = 0;
	e_num = -1;
	while (i < info->have_pipe + 1)
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
	{
		if (info->pids[i++] == -2)
		{
<<<<<<< HEAD
			i++;
			continue ;
		}
		waitpid(info->pids[i++], 0, 0);
	}
	//마지막 명령어만 status 가져오기
	if (info->pids[i] != -2)
	{
		waitpid(info->pids[i], &status, 0);
		g_exit_num = (status & 0xff00) >> 8;
=======
			e_num = -1;
			continue ;
		}
		waitpid(info->pids[i++], &status, 0);
		e_num = (status & 0xff00) >> 8;
	}
	if (info->here_doc)
	{
		free(info->pids);
		return ;
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
	}
	if (e_num != -1)
		g_exit_num = e_num;
	free(info->pids);
}

<<<<<<< HEAD
void	parsing(char **bundles, t_info *info)
=======
void	parsing(char **bundles, t_info *info) //25줄 초과!!
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
{
	int		i;
	char	**parts;

	info->have_pipe = info->pipe_num;
	i = -1;
	while (bundles[++i])
	{
<<<<<<< HEAD
		info->r_in_fd = -1;
		info->r_out_fd = -1;
		info->r_kind = 0;
		parts = 0;
		if (solve_redirect(bundles[i], info) != -2)
		{
			parts = split_words(bundles[i]);
=======
		info->r_in_fd = -1; //init 함수 새로 만들기?
		info->r_out_fd = -1;
		info->r_kind = 0;
		info->here_doc = 0;
		parts = 0;
		info->pids[i] = -2;
		if (solve_redirect(bundles[i], info) != -2)
		{
			parts = split_words(bundles[i], info);
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
			if (parts && interpret_word(parts, info))
				info->pids[i] = command(parts, info);
			else
				g_exit_num = 1;
		}
		else
			g_exit_num = 1;
		info->pipe_num--;
		free_str(parts);
	}
}

void	minishell(char *input, t_info *info)
{
	if (check_syntax(input, info))
	{
		ft_print_error(0, 0, "syntax error near unexpected token");
<<<<<<< HEAD
		g_exit_num = 2;//check
		return ;
	}
	info->bundles = pipe_parsing(input, info);
	if (!(info->bundles))
	{
		g_exit_num = 1;
		return ;
	}
=======
		g_exit_num = 258;//check 수정 필요할듯
		return ;
	}
	info->bundles = pipe_parsing(input, info);
	if (!(info->bundles))
		free_exit(info);
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
	info->pids = (pid_t *)malloc(sizeof(pid_t) * (info->pipe_num + 1));
	if (!(info->pids))
	{
		ft_print_error(0, 0, strerror(errno));
<<<<<<< HEAD
		free_str(info->bundles);
		g_exit_num = 1;
		return ;
=======
		free_exit(info);
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
	}
	parsing(info->bundles, info);
	free_pid(info);
	free_str(info->bundles);
}

<<<<<<< HEAD
void	ft_readline(t_info *info)
{
	char	*input;

	init_ctrl();
	while (1)
	{
=======
void	ft_readline(t_info *info) //25줄 확인!!
{
	char	*input;

	while (1)
	{
		init_ctrl();
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
		init_reset(info);
		input = readline("\033[0;31mminishell$ \033[0;37m");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		else if (input[0] == '\0')
<<<<<<< HEAD
		{
=======
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
			free(input);
		else
		{
			add_history(input);
			minishell(input, info);
			free(input);
		}
		if (info->exit == 1)
			break ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc == 1 && argv[0])
	{
		if (!init_env(&info, envp))
		{
			free_list(&(info.env_list));
			return (0);
		}
		ft_readline(&info);
		free_all(&info);
	}
	else
	{
		ft_print_error(0, 0, "too many parameters\n");
	}
<<<<<<< HEAD
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc == 1 && argv[0])
	{
		if (!init_env(&info, envp))
			return (0);
		init(&info);
		ft_readline(&info);
		free_all(&info);
	}
	else
	{
		ft_print_error(0, 0, "too many parameters\n");
	}
=======
	//leaks
	system("leaks minishell > leaks_result; cat leaks_result | grep leaked; rm -rf leaks_result");
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
	return (0);
}