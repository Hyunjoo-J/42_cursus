/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 02:45:49 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/25 04:17:10 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
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
