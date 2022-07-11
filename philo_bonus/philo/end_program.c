/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:33:28 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/12 02:33:29 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	malloc_er(t_data *data)
{
	if (data->philos)
		free(data->philos);
	write(2, "Error: MALLOC ERROR\n", 20);
}

int	end_program(int err, t_data *data)
{
	if (err == WRONG_ARGUMENTS)
		write(2, "Error: WRONG ARGUMENTS\n", 23);
	if (err == MALLOC_ERROR)
		malloc_er(data);
	return (1);
}
