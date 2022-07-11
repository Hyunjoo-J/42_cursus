/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:34:00 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/12 02:34:00 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_philo *philo, char *str)
{
	unsigned int	now;

	pthread_mutex_lock(&philo->data->print);
	now = get_time();
	printf("%u\t%d\t%s\n", now - philo->data->create_date, philo->n + 1, str);
	pthread_mutex_unlock(&philo->data->print);
}
