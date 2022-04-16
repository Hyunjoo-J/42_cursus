/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2_keep_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:05:13 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/16 17:43:46 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	largest_keep_a(t_s_elem *start, t_stack *stack, bool define)
{
	t_s_elem	*elem;
	int			index_max;
	int			count;

	elem = start;
	index_max = 0;
	count = 0;
	while (elem)
	{
		if (elem->t_i >= index_max)
		{
			if (define)
				elem->keep = true;
			index_max = elem->t_i;
			++count;
		}
		else if (define)
			elem->keep = false;
		elem = elem->next;
		if (elem == NULL)
			elem = stack->first;
		if (elem == start)
			break ;
	}
	return (count);
}

t_s_elem	*get_max_keep(t_stack *stack)
{
	t_s_elem	*elem;
	t_s_elem	*max;
	int			max_keep;
	int			cur;

	max_keep = 0;
	elem = stack->first;
	while (elem)
	{
		cur = largest_keep_a(elem, stack, false);
		if (cur > max_keep)
		{
			max_keep = cur;
			max = elem;
		}
		elem = elem->next;
	}
	return (max);
}

void	set_keep(t_mem *mem)
{
	t_s_elem	*max;
	t_stack		*stack;

	stack = mem->a;
	max = get_max_keep(stack);
	mem->maxsize = largest_keep_a(max, stack, true);
}

void	push_keep_false_b(t_mem *mem)
{
	int	size;

	size = stack_length(mem->a) - mem->maxsize;
	while (size > 0)
	{
		if (mem->a->first->keep == false)
		{
			pb(mem->a, mem->b, 1, mem);
			size--;
		}
		else
			ra(mem->a, 1, mem);
	}
}
