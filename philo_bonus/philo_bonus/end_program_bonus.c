/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:25:17 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/12 03:25:18 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	sem_er(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->forks != SEM_FAILED)
		sem_close(data->forks);
	if (data->main != SEM_FAILED)
		sem_close(data->main);
	if (data->print != SEM_FAILED)
		sem_close(data->print);
}

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
	if (err == SEM_ERROR)
		sem_er(data);
	return (1);
}
