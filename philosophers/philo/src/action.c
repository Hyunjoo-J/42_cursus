/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:12:05 by hyjeong           #+#    #+#             */
/*   Updated: 2022/05/11 15:19:04 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_info *info, int id)
{
	int	ret;

	check_philo(info);
	if (info->number != 1)
		ret = philo_print(info, 2, id);
	if (id % 2 == 0)
	{
		if (id == 0)
			pthread_mutex_unlock(&((info->forks)[info->number - 1]));
		else
			pthread_mutex_unlock(&((info->forks)[id - 1]));
	}
	if (info->number == 1)
		return ;
	pthread_mutex_unlock(&((info->forks)[id]));
	if (id % 2 == 1)
		pthread_mutex_unlock(&((info->forks)[id - 1]));
	if (ret != -1)
	{
		if (info->sleep != 0)
			sleep_check(info->sleep);
		philo_think(info, id);
	}
}

void	fair_wait_fork(t_info *info, int id, int comp, int dst)
{
	while (1)
	{
		if (id > comp)
			pthread_mutex_lock(&(info->philos[id].mutex));
		pthread_mutex_lock(&(info->philos[comp].mutex));
		if (id < comp)
			pthread_mutex_lock(&(info->philos[id].mutex));
		if ((info->philos)[comp].count > (info->philos)[id].count || \
		((info->philos)[comp].count == (info->philos)[id].count && \
		id % 2 == 0))
		{
			pthread_mutex_unlock(&(info->philos[id].mutex));
			pthread_mutex_unlock(&(info->philos[comp].mutex));
			pthread_mutex_lock(&((info->forks)[dst]));
			philo_print(info, 0, id);
			break ;
		}
		pthread_mutex_unlock(&(info->philos[id].mutex));
		pthread_mutex_unlock(&(info->philos[comp].mutex));
		if (info->die == 0)
			break ;
	}
}

void	philo_think(t_info *info, int id)
{
	check_philo(info);
	philo_print(info, 3, id);
	philo_eat(info, id);
}

void	philo_eat(t_info *info, int id)
{
	if (id == 0)
		fair_wait_fork(info, id, info->number - 1, info->number - 1);
	else if (id % 2 == 0)
		fair_wait_fork(info, id, id - 1, id - 1);
	if (info->number != 1 && id == (info->number - 1))
		fair_wait_fork(info, id, 0, id);
	else if (info->number != 1)
		fair_wait_fork(info, id, id + 1, id);
	if (id % 2 == 1)
		fair_wait_fork(info, id, id - 1, id - 1);
	if (info->number != 1 && info->die > 0 && !check_philo(info))
	{
		pthread_mutex_lock(&(info->philos[id].mutex));
		gettimeofday(&((info->philos)[id].t_eat), 0);
		pthread_mutex_unlock(&(info->philos[id].mutex));
		philo_print(info, 1, id);
		if (info->eat != 0)
			sleep_check(info->eat);
		else
			usleep(50);
		pthread_mutex_lock(&(info->philos[id].mutex));
		(info->philos)[id].count++;
		pthread_mutex_unlock(&(info->philos[id].mutex));
	}
	philo_sleep(info, id);
}

void	*init_philo(void *arg)
{
	t_info	*info;
	int		cur_id;

	info = ((t_arg *)arg)->info;
	cur_id = ((t_arg *)arg)->id;
	free((t_arg *)arg);
	pthread_mutex_lock(&(info->philos[cur_id].mutex));
	((info)->philos)[cur_id].id = cur_id;
	((info)->philos)[cur_id].count = 0;
	pthread_mutex_unlock(&(info->philos[cur_id].mutex));
	philo_eat(info, cur_id);
	return (0);
}
