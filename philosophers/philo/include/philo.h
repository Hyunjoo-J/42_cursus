/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:02 by hyjeong           #+#    #+#             */
/*   Updated: 2022/05/10 17:57:34 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483649

typedef struct	s_philo{
	int	id;
	struct timeval	t_eat;
	int	count;
	pthread_mutex_t	mutex;
}	t_philo;

typedef struct s_info {
	pthread_t			*g_threads;
	pthread_mutex_t		*g_forks;
	pthread_mutex_t		g_mutex;
	t_philo				*g_philos;
	int					g_number;
	int					g_t_die;
	int					g_t_eat;
	int					g_t_sleep;
	int					g_count;
	struct timeval		g_start;
}				t_info;

typedef struct s_arg {
	t_info	*info;
	int		id;
}				t_arg;

int		ft_atoi(char *str);
double	get_time(struct timeval *start, struct timeval *end);
int		philo_print(t_info *info, int type, int id);
int		start_mutex(t_info *info);
int		check_starvation(t_info *info);
void	sleep_check(int dst);
int		update_end(t_info *info);

int		check_philo(t_info *info);
int		free_data(int m, int n, t_arg *arg, t_info *info);

void	*init_philo(void *info);
void	fair_wait_fork(t_info *info, int id, int comp, int dst);
void	philo_eat(t_info *info, int id);
void	philo_think(t_info *info, int id);
void	philo_sleep(t_info *info, int id);

#endif