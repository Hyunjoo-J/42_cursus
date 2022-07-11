/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:25:06 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/12 03:25:07 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_eat(void *arg)
{
	int		i;
	t_data	*data;

	data = arg;
	i = -1;
	while (++i < data->num_of_philos)
	{
		sem_wait(data->twoforks);
		usleep(100);
	}
	sem_post(data->main);
	return (0);
}

void	*check_death(void *arg)
{
	t_philo			*philo;
	unsigned int	now;
	int				i;

	i = -1;
	philo = arg;
	while (philo->data->finish == 0)
	{
		now = get_time();
		if (now >= philo->death_time)
		{
			philo->data->finish = 1;
			print_philo(philo, "died");
			sem_wait(philo->eat);
			sem_post(philo->data->main);
			while (++i < philo->data->num_of_must_eat)
				sem_post(philo->data->twoforks);
		}
		usleep(100);
	}
	return (0);
}
