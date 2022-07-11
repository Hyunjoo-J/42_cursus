/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:25:35 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/12 03:25:35 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_philo(t_philo *philo, char *str)
{
	unsigned int	now;

	now = get_time();
	sem_wait(philo->data->print);
	printf("%u\t%d\t%s\n", now - philo->data->create_date, philo->n + 1, str);
	if (philo->data->finish == 1)
		return ;
	sem_post(philo->data->print);
}
