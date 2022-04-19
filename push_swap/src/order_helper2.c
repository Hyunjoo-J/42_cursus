/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:31:10 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/20 04:31:11 by hyunjoo          ###   ########.fr       */
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
