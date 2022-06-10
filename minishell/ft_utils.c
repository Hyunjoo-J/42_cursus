/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:59:12 by hyunjoo           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/09 16:48:53 by hyjeong          ###   ########.fr       */
=======
/*   Updated: 2022/06/05 14:10:07 by hyjeong          ###   ########.fr       */
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	ft_print_error(char *cmd, char *arg, char *msg)
{
	int fd;

	fd = 2;
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
	//ft_reset_uni();
	//free_env();
	exit(exit_status);
}

<<<<<<< HEAD
void	ft_oldpwd(t_info *info, char *path)
=======
void	ft_oldpwd(t_list *env, char *path)
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
{
	char	*tmp;
	char	*new_path;
	t_list	*new1;
	t_list	*new2;

<<<<<<< HEAD
	new1 = info->env_list;
	new_path = getcwd(NULL, 0);
	tmp = malloc(sizeof(char) * MAXSIZE);
	if (list_find(new1, "OLDPWD"))
	{
		while (new1->key != "OLDPWD")
			new1 = new1->next;
		new1->value = path;

	}
	if (list_find(new2,"PWD"))
	{
		while (new2->key != "PWD")
			new2 = new2->next;
		new2->value = new_path;
	}
}
=======
	new1 = env;
	new_path = getcwd(NULL, 0);
	tmp = malloc(sizeof(char) * MAXSIZE);
	if (list_find(&new1, "OLDPWD"))
	{
		list_insert(&(env), new_item(ft_strdup("OLDPWD"), ft_strdup(path), 1));
	}
	if (list_find(&new2,"PWD"))
	{
		list_insert(&(env), new_item(ft_strdup("PWD"), ft_strdup(new_path), 1));
	}
}
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
