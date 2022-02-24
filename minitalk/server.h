/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:15:46 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/25 03:27:16 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_sig
{
	char			symbol;
	unsigned int	bit;
	pid_t			pid;
}	t_sig;
t_sig	g_sig;

#endif
