/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:01:39 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/16 17:01:48 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	find_duplicate_small(t_stack *a)
{
	int			i;
	t_s_elem	*elem;
	t_s_elem	*tmp;

	i = 0;
	tmp = a->first;
	while (tmp->next)
	{
		elem = tmp->next;
		while (elem)
		{
			if (tmp->value == elem->value)
			{
				i++;
				break ;
			}
			elem = elem->next;
		}
		tmp = tmp->next;
	}
	return (i);
}

int	is_sorted_stack(t_stack *a)
{
	t_s_elem	*elem;

	elem = a->first;
	while (elem->next)
	{
		if (elem->next->value < elem->value)
			return (ERROR);
		elem = elem->next;
	}
	return (SUCCESS);
}
