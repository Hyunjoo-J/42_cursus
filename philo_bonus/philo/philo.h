/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:33:52 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/12 03:32:27 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define WRONG_ARGUMENTS 1
# define MALLOC_ERROR 2
# define PTHREAD_CREATE_ERROR 3
# define PTHREAD_JOIN_ERROR 4

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*                Data && Structures               */

typedef struct s_philo
{
	int				n;
	int				n1;
	int				num_of_eat;
	unsigned int	death_time;
	pthread_t		thread;
	struct s_data	*data;
	pthread_mutex_t	eating;
}					t_philo;

typedef struct s_data
{
	int				num_of_philos;
	unsigned int	time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				finish;
	int				eat_finish;
	unsigned int	create_date;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	main;
	t_philo			*philos;
}					t_data;

/*                MAIN FUNCTIONS                */
int				data_fill(int ac, char **av, t_data *data);
int				data_join(t_data *data);
void			*monitor(void *arg);
void			*check_death(void *arg);
void			*check_eat(void *arg);

/*                ERROR FUNCTIONS                */
int				check_args(int ac, char **av);
int				end_program(int err, t_data *data);

/*                UTILS FUNCTIONS                */
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
unsigned int	get_time(void);
void			print_philo(t_philo *philo, char *str);

#endif
