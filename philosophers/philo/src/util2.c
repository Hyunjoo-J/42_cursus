/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:12:00 by hyjeong           #+#    #+#             */
/*   Updated: 2022/05/11 15:22:13 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_check(int dst)
{
	struct timeval	start;

	gettimeofday(&start, 0);
	while (get_time(&start, 0) < (double)(dst))
		usleep(50);
}

int	update_end(t_info *info)
{
	info->die = 0;
	return (-1);
}
