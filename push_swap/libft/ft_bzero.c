/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD:push_swap/libft/ft_bzero.c
/*   By: suko <suko@stduent.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:21:36 by suko              #+#    #+#             */
/*   Updated: 2020/12/26 18:49:14 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
=======
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:07:29 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/16 17:07:31 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SUCCESS 1
# define ERROR 0
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <common/common.h>
# include <sorter/sorter.h>
#endif
>>>>>>> 68a3d98e2905d1367baf38962dc4fe25d21fc091:push_swap/push_swap.h
