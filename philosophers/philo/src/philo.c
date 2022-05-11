/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:11:48 by hyjeong           #+#    #+#             */
/*   Updated: 2022/05/11 15:21:07 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fill_opt(int argc, char **argv, t_info *info)
{
	info->number = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (info->number <= 0 || info->die < 0 || info->eat < 0 || \
	info->sleep < 0)
		return (-1);
	if (info->die == 0)
	{
		printf("%d %d died\n", 0, 1);
		return (-1);
	}
	if (argc == 6)
	{
		info->count = ft_atoi(argv[5]);
		if (info->count < 0)
			return (-1);
	}
	else
		info->count = -1;
	return (0);
}

int	free_data(int m, int n, t_arg *arg, t_info *info)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_join((info->threads)[i], 0);
	i = -1;
	while (++i < (m - info->number))
		pthread_mutex_destroy(&(info->philos[i].mutex));
	i = -1;
	while (++i < m && i < info->number)
		pthread_mutex_destroy(&(info->forks[i]));
	i = -1;
	if (m >= 0)
		pthread_mutex_destroy(&info->mutex);
	if (info->threads != 0)
		free(info->threads);
	if (info->forks != 0)
		free(info->forks);
	if (info->philos != 0)
		free(info->philos);
	if (arg != 0)
		free(arg);
	return (-1);
}

int	start_data(t_info *info)
{
	int		i;
	t_arg	*arg;

	if (start_mutex(info))
		return (-1);
	i = -1;
	while (++i < info->number)
		gettimeofday(&(((info)->philos)[i].t_eat), 0);
	i = -1;
	gettimeofday(&(info->start), 0);
	while (++i < info->number)
	{
		arg = malloc(sizeof(t_arg));
		if (arg)
			arg->info = info;
		if (arg)
			arg->id = i;
		if (!arg || \
		pthread_create(&((info->threads)[i]), 0, init_philo, (void *)arg))
			return (free_data(info->number, i, arg, info));
	}
	return (0);
}

int	check_philo(t_info *info)
{
	int				i;

	pthread_mutex_lock(&(info->mutex));
	if (info->die == 0)
	{
		pthread_mutex_unlock(&(info->mutex));
		return (update_end(info));
	}
	pthread_mutex_unlock(&(info->mutex));
	if (check_starvation(info))
		return (update_end(info));
	i = -1;
	while (++i < info->number)
	{
		pthread_mutex_lock(&(info->philos[i].mutex));
		if (info->count == -1 || (info->philos)[i].count < info->count)
		{
			pthread_mutex_unlock(&(info->philos[i].mutex));
			break ;
		}
		pthread_mutex_unlock(&(info->philos[i].mutex));
	}
	if (i == info->number)
		return (update_end(info));
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if ((argc != 5 && argc != 6) || fill_opt(argc, argv, &info))
		return (0);
	info.forks = malloc(sizeof(pthread_mutex_t) * info.number);
	info.threads = malloc(sizeof(pthread_t) * info.number);
	info.philos = malloc(sizeof(t_philo) * info.number);
	if (info.forks == 0 || info.threads == 0 || info.philos == 0)
		free_data(0, 0, 0, &info);
	else if (!start_data(&info))
	{
		while (1)
		{
			usleep(5000);
			if (check_philo(&info))
				break ;
		}
		free_data(info.number, info.number, 0, &info);
	}
	return (0);
}
