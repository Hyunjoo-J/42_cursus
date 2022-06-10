/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:37:23 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/09 23:37:24 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	pwd 뒤에 어떤 파라미터가 오던지 상관없음
	대신 옵션이 들어오는 순간 오류 출력
	옵션은 따옴표에 상관없이 -[c]가 오면 인식
*/
#include "../includes/minishell.h"

int	ft_pwd(char **cmd, t_info *info)
{
<<<<<<< HEAD
	int	i;
=======
	int		i;
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
	char	*path;

	if (cmd[1])
	{
		i = 0;
		if (cmd[1][i] == '-')
		{
			cmd[1][i + 2] = 0;
			ft_print_error(cmd[0], cmd[1], "invalid option");
			return (1);
<<<<<<< HEAD
=======
		}
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
	}
	path = getcwd(NULL, 0);
	if (!path)
	{
		ft_print_error(cmd[0],cmd[1],strerror(errno));
		return (1);
	}
<<<<<<< HEAD
	printf("%s\n", path);
	free(path);
	return (0);
}
=======
	ft_print(info, path);
	ft_print(info, "\n");
	free(path);
	return (0);
}
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
