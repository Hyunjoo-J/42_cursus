/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 02:43:01 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/05 02:38:59 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define CMD 0
# define ARG 1
# define OPT 2
# define PIPE 3
# define RED 4
# define DOLLAR 5

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <string.h>

typedef struct s_list
{
	char	*key;
	char	*value;
	int		print;
	struct s_list	*next;
}	t_list;

typedef struct s_info
{
	char	*home;
	char	**envp;
	t_list	*list;
}	t_info;

typedef struct s_lexer
{
	char				*str;
	int					type;
	int					quote;
	int					connect;
	struct s_lexer		*next;
}t_lexer;

int	g_exit_num;

#endif