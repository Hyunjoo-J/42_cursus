/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:15:46 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/24 02:34:18 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_sig
{
	char	symbol;
	unsigned int	bit;
	pid_t	pid;
}	t_sig;
t_sig	g_sig;

#endif