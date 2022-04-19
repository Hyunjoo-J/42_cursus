/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step4_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:04:26 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/16 17:04:46 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	sort_mins(t_mem *mem, t_params *params)
{
	while (params->min_b > 0 && params->min_a > 0)
	{
		rr(mem->a, mem->b, 1, mem);
		params->min_b--;
		params->min_a--;
	}
	while (params->min_a < 0 && params->min_b < 0)
	{
		rrr(mem->a, mem->b, 1, mem);
		params->min_b++;
		params->min_a++;
	}
	return (SUCCESS);
}

int	sort(t_mem *mem, t_params *params)
{
	if ((params->min_b > 0 && params->min_a > 0)
		|| (params->min_b < 0 && params->min_a < 0))
		sort_mins(mem, params);
	while (params->min_b > 0)
	{
		rb(mem->b, 1, mem);
		(params->min_b)--;
	}
	while (params->min_b < 0)
	{
		rrb(mem->b, 1, mem);
		params->min_b++;
	}
	while (params->min_a > 0)
	{
		ra(mem->a, 1, mem);
		(params->min_a)--;
	}
	while (params->min_a < 0)
	{
		rra(mem->a, 1, mem);
		params->min_a++;
	}
	pa(mem->b, mem->a, 1, mem);
	return (SUCCESS);
}
