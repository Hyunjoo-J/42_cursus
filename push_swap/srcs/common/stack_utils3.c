/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:00:35 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/16 17:00:46 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	check_duplicates(t_mem *mem)
{
	t_s_elem	*elem1;
	t_s_elem	*elem2;

	elem1 = mem->a->first;
	elem2 = mem->a->first;
	while (elem2)
	{
		elem1 = mem->a->first;
		while (elem1)
		{
			if (elem1->value == elem2->value && elem1 != elem2)
				error(mem, 1, NULL, NULL);
			elem1 = elem1->next;
		}
		elem2 = elem2->next;
	}
}

int	abs_value(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_params	init_params(t_mem *mem)
{
	t_params	params;

	params.c_for_a = 0;
	params.c_for_b = 0;
	params.elem = mem->b->first;
	params.best = NULL;
	params.min_a = 0;
	params.min_b = 0;
	params.min_move = 0xFFFFFFF;
	params.action_b = 0;
	params.total = 0;
	return (params);
}
