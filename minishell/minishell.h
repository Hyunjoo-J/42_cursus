/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 02:43:01 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/05/27 01:36:38 by hyunjoo          ###   ########.fr       */
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

typedef struct s_parser
{
	t_lexer			*start;
	t_lexer			*end;
	int				pipe[2];
	int				fd_in;
	int				fd_out;
	struct s_parser	*next;
	size_t			pid;
}t_parser;

typedef struct s_env
{
	char			*key;
	char			*val;
	int				check;
	struct s_env	*next;
}t_env;

typedef struct s_uni
{
	t_lexer		*lexer_list;
	t_parser	*parser_list;
	int			exit_status;
	t_env		*env_list;
	char		*input;
}t_uni;

t_uni	g_uni;

#endif