/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:02:32 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/16 17:02:34 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rotate_stack(t_stack *sta)
{
	t_s_elem	*last;
	t_s_elem	*tmp;

	if (!sta)
		return ;
	last = last_element(sta);
	tmp = sta->first;
	sta->first = sta->first->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	ra(t_stack *a, int print_option, t_mem *mem)
{
	if (!a || !mem)
		return ;
	rotate_stack(a);
	if (print_option == 1)
		write(1, "ra\n", 3);
	mem->action_count++;
}

void	rb(t_stack *b, int print_option, t_mem *mem)
{
	if (!b || !mem)
		return ;
	rotate_stack(b);
	if (print_option == 1)
		write(1, "rb\n", 3);
	mem->action_count++;
}

void	rr(t_stack *a, t_stack *b, int print_option, t_mem *mem)
{
	if (!b || !mem || !a)
		return ;
	rotate_stack(a);
	rotate_stack(b);
	if (print_option == 1)
		write(1, "rr\n", 3);
	mem->action_count++;
}

t_s_elem	*last_element(t_stack *sta)
{
	t_s_elem	*elem;

	if (!sta || !sta->first)
		return (NULL);
	elem = sta->first;
	while (elem->next)
		elem = elem->next;
	return (elem);
}
