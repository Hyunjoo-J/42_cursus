/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:30:56 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/20 04:30:59 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	int	temp;

	if (stack->next == 0 || stack->next->next == 0)
		return (-1);
	temp = stack->next->val;
	stack->next->val = stack->next->next->val;
	stack->next->next->val = temp;
	return (0);
}

int	push(t_stack *from, t_stack *to)
{
	t_stack	*temp;

	temp = from->next;
	if (temp == 0)
		return (-1);
	temp->prev = to;
	if (to->next != 0)
		to->next->prev = temp;
	if (temp->next != 0)
		temp->next->prev = from;
	from->next = temp->next;
	temp->next = to->next;
	to->next = temp;
	return (0);
}

int	rotate(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*temp;

	temp = stack->next;
	if (temp == 0 || temp->next == 0)
		return (-1);
	stack->next = temp->next;
	temp->next->prev = stack;
	curr = stack->next;
	while (curr->next != 0)
		curr = curr->next;
	curr->next = temp;
	temp->prev = curr;
	temp->next = 0;
	return (0);
}

int	reverse_rotate(t_stack *stack)
{
	t_stack	*temp;

	temp = stack->next;
	if (temp == 0 || temp->next == 0)
		return (-1);
	while (temp->next != 0)
		temp = temp->next;
	stack->next->prev = temp;
	temp->next = stack->next;
	temp->prev->next = 0;
	temp->prev = stack;
	stack->next = temp;
	return (0);
}
