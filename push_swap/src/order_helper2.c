/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:26:30 by suko              #+#    #+#             */
/*   Updated: 2021/06/29 18:32:01 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_compression(t_order *temp, t_order *curr)
{
	if ((temp->order[0] == 's' && curr->order[0] == 's' &&\
	temp->order[1] == curr->order[1]) || (temp->order[0] == 'p' &&\
	curr->order[0] == 'p' && temp->order[1] != curr->order[1]) ||\
	(temp->order[0] == 'r' && curr->order[0] == 'd' &&\
	(temp->order[1] == curr->order[1] || (temp->order[1] == 'r' &&\
	curr->order[0] == 'd'))) || (temp->order[0] == 'd' &&\
	curr->order[0] == 'r' && (temp->order[1] == curr->order[1] ||\
	(temp->order[1] == 'd' && curr->order[0] == 'r'))))
		return (1);
	else if (temp->order[1] == temp->order[0] ||\
	curr->order[1] == curr->order[0] || temp->order[1] == curr->order[1] ||\
	temp->order[0] == 'p' || curr->order[0] == 'p')
		return (-1);
	return (0);
}
