#include "../includes/minishell.h"

int	is_builtin(char *command)
{
	return (ft_strcmp(command, "pwd") == 0 || ft_strcmp(command, "unset") == 0
		|| ft_strcmp(command, "export") == 0 || ft_strcmp(command, "echo") == 0
		|| ft_strcmp(command, "env") == 0 || ft_strcmp(command, "cd") == 0
		|| ft_strcmp(command, "exit") == 0);
}

int	builtin_command(char **command, t_info *info) // 명령어 추가
{
	int	status;

	set_output_fd(info);
	if (ft_strcmp(command[0], "pwd") == 0)
		status = ft_pwd(command, info);
	else if (ft_strcmp(command[0], "unset") == 0)
		status = ft_unset(command, info);
	else if (ft_strcmp(command[0], "export") == 0)
		status = ft_export(command, info);
	else if (ft_strcmp(command[0], "echo") == 0)
		status = ft_echo(command, info);
	else if (ft_strcmp(command[0], "env") == 0)
		status = ft_env(command, info);
	else if (ft_strcmp(command[0], "cd") == 0)
		status = ft_cd(command, info);
	else if (ft_strcmp(command[0], "exit") == 0)
		status = ft_exit(command, info);
	g_exit_num = status;
	return (status);
}

void	ft_print(t_info *info, char *str)
{
	write(info->output_fd, str, ft_strlen(str));
}

void	set_output_fd(t_info *info)
{
	if (info->r_out_fd != -1)
	{
		if (info->output_fd != 1)
			close(info->output_fd);
		info->output_fd = info->r_out_fd;
	}
}

void	set_input_fd(t_info *info)
{
	//자식 프로세스 안에서 input은 dup2를 사용하면되지만
	if (info->r_in_fd != -1)
	{
		if (info->input_fd != 0)
			close(info->input_fd);
		dup2(info->r_in_fd, STDIN_FILENO);
		close(info->r_in_fd);
	}
	else
	{
		dup2(info->input_fd, STDIN_FILENO);
		if (info->input_fd != 0)
			close(info->input_fd);
	}
	//output은 나중에 출력을 할 때 문제가 생김(빌트인 함수)
}
//pipe 사용하면 dup2사용하기 때문에 printf가 편함
//사용안하면 write를 사용해야하는