/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 03:28:43 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/08 03:29:12 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	reverse_rotate(t_stack *sta)
{
	t_s_elem	*prev;
	t_s_elem	*elem;

	if (!sta->first || !sta->first->next || !sta)
		return ;
	elem = sta->first;
	while (elem->next)
	{
		prev = elem;
		elem = elem->next;
	}
	elem->next = sta->first;
	sta->first = elem;
	prev->next = NULL;
}

void	rra(t_stack *a, int print_option, t_mem *mem)
{
	reverse_rotate(a);
	if (print_option == 1)
		write(1, "rra\n", 4);
	mem->action_count++;
}

void	rrb(t_stack *b, int print_option, t_mem *mem)
{
	reverse_rotate(b);
	if (print_option == 1)
		write(1, "rrb\n", 4);
	mem->action_count++;
}

void	rrr(t_stack *a, t_stack *b, int print_option, t_mem *mem)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print_option == 1)
		write(1, "rrr\n", 4);
	mem->action_count--;
}