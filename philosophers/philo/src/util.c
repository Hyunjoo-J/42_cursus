/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:11:55 by hyjeong           #+#    #+#             */
/*   Updated: 2022/05/11 15:22:09 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				flag;
	long			num;

	i = 0;
	num = 0;
	flag = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		if ((flag == 0 && num > INT_MAX) || (flag == -1 && num > -INT_MIN))
			return (-1);
		i++;
	}
	return (flag * num);
}

int	start_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&(info->mutex), 0))
		return (free_data(-1, 0, 0, info));
	i = -1;
	while (++i < info->number)
		if (pthread_mutex_init(&(info->forks[i]), 0))
			return (free_data(i, 0, 0, info));
	i = -1;
	while (++i < info->number)
		if (pthread_mutex_init(&(info->philos[i].mutex), 0))
			return (free_data(info->number + i, 0, 0, info));
	return (0);
}

int	check_starvation(t_info *info)
{
	int				i;
	double			diff;
	struct timeval	curr;

	i = -1;
	while (++i < info->number)
	{
		gettimeofday(&curr, 0);
		pthread_mutex_lock(&(info->philos[i].mutex));
		diff = get_time(&((info->philos)[i].t_eat), &curr);
		if (diff >= info->die)
		{
			philo_print(info, 4, i);
			pthread_mutex_lock(&(info->mutex));
			info->die = 0;
			pthread_mutex_unlock(&(info->mutex));
			pthread_mutex_unlock(&(info->philos[i].mutex));
			return (-1);
		}
		pthread_mutex_unlock(&(info->philos[i].mutex));
	}
	return (0);
}

double	get_time(struct timeval *start, struct timeval *end)
{
	double			diff;
	struct timeval	temp;

	if (end != 0)
	{
		diff = (end->tv_sec - start->tv_sec) * 1000 + \
		((end->tv_usec - start->tv_usec) / 1000);
	}
	else
	{
		gettimeofday(&temp, 0);
		diff = (temp.tv_sec - start->tv_sec) * 1000 + \
		((temp.tv_usec - start->tv_usec) / 1000);
	}
	return (diff);
}

int	philo_print(t_info *info, int type, int id)
{
	static int		ret = 0;

	pthread_mutex_lock(&(info->mutex));
	if (ret == 0 && type == 4)
	{
		ret = -1;
		printf("%.lf %d died\n", get_time(&(info->start), 0), id + 1);
	}
	else if (ret == 0 && type != 4 && info->die > 0)
	{
		printf("%.lf %d ", get_time(&(info->start), 0), id + 1);
		if (type == 0)
			printf("has taken a fork\n");
		else if (type == 1)
			printf("is eating\n");
		else if (type == 2)
			printf("is sleeping\n");
		else
			printf("is thinking\n");
	}
	else
		ret = -1;
	pthread_mutex_unlock(&(info->mutex));
	return (ret);
}
