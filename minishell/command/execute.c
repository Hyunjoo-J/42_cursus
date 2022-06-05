#include "../includes/minishell.h"

void	execute(char **command, char **envp)
{
	char	*path;

	path = find_path(command[0], envp);
	if (execve(path, command, envp) == -1)
	{
		dup2(1, STDOUT_FILENO);
		printf("minishell: %s:command not found\n", command[0]);// 수정!!!!!!! 출력 위치가 이상해!! + exit_num처리127
		exit(EXIT_FAILURE);
	}
}

void	set_redirection(t_info *info)
{
	if (info->redirect_in != -1)
	{
		if (info->input_file != 0)
			close(info->input_file);
		dup2(info->redirect_in, STDIN_FILENO);
		close(info->redirect_in);
	}
	else
	{
		dup2(info->input_file, STDIN_FILENO);
		if (info->input_file != 0)
			close(info->input_file);
	}
	if (info->redirect_out != -1)
	{
		dup2(info->redirect_out, STDOUT_FILENO);
		close(info->redirect_out);
	}
	else
	{
		dup2(info->output_file, STDOUT_FILENO);
	}
}

pid_t	last_execute(char **command, t_info *info)//단순 실행
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		printf("error\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (builtin_command(command, info))
			exit(0);
		else
		{
			set_redirection(info);
			execute(command, info->envp);
		}
	}
	return (pid);
}
//echo hello | grep h

/*포크 사용 부모 및 자식 프로세스 생성 / ls가 들어오면 execv를 사용하여 명령어 실행 -> 부모 프로세스에 이 함수를 사용하면 완전 다른 프로그램 원하는 것 실행 못하고 끝남 자식 프로세서 끝내고 부모프로세스에서 작동 wait pid로 자식이 끝날 때까지 기다렸다가 부모프로세스에서 마저 작동, 파이프 사용시 부모 자식 프로세스 복제 그 뒤로는 서로 간섭 불가 ls | grep과 같이 실행하면 ls 결과가 파이프에 들어가 grep에서 사용 파이프는 프로세스 간의 통신
빌트인 execv사용하지 않음. 빌트인함수 사용하면 exit 따로 처리 그 외는 알아서 종료 후 프로세스 처리
정의 되어있지 않은 명령어 -> 마지막 파이프? 따로 확인(나중에)
a(정의X) | b | c
*/
