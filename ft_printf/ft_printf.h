/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 01:38:12 by hyunjoo           #+#    #+#             */
/*   Updated: 2021/10/28 03:04:42 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <cstdarg>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	flags
{
	int	minus;
	int	plus;
	int	zero;
	int	wspace;
	int	sharp;
	int	dig;
	int	pre;
	int	var_width;
	int	var_pre;
	int	space;
	int	dot;
}t_flag;

#endif