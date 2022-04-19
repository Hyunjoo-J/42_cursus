/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:30:49 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/20 04:30:51 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_count(t_stack *stack)
{
	t_stack	*curr;
	int		count;

	curr = stack->next;
	count = 0;
	while (curr != 0)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

int		is_sorted(t_stack *stack, int count, int type)
{
	t_stack *curr;
	t_stack *next;
	int		i;

	curr = stack->next;
	i = 0;
	while (curr->next != 0 && i < (count - 1))
	{
		next = curr->next;
		if (type == 0 && curr->val > next->val)
			return (-1);
		else if (type == 1 && curr->val < next->val)
			return (-1);
		i++;
		curr = next;
	}
	return (0);
}

int		get_value(t_stack *stack, int index)
{
	t_stack *curr;
	int		i;

	curr = stack->next;
	i = 0;
	while (curr != 0 && i <= index)
	{
		if (i == index)
			return (curr->val);
		i++;
		curr = curr->next;
	}
	return (0);
}

int		ft_strcmp(char *a, char *b)
{
	int	i;

	i = -1;
	while (a[++i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
			return (-1);
	}
	if (a[i] == b[i])
		return (0);
	else
		return (-1);
}

void	print_and_do(t_stack *a, t_stack *b, char **ops, t_order *ords)
{
	int	i;

	i = -1;
	while (ops[++i] != 0)
	{
		store(ops[i], ords);
		if (!ft_strcmp(ops[i], "sa") || !ft_strcmp(ops[i], "ss"))
			swap(a);
		if (!ft_strcmp(ops[i], "sb") || !ft_strcmp(ops[i], "ss"))
			swap(b);
		if (!ft_strcmp(ops[i], "pa"))
			push(b, a);
		if (!ft_strcmp(ops[i], "pb"))
			push(a, b);
		if (!ft_strcmp(ops[i], "ra") || !ft_strcmp(ops[i], "rr"))
			rotate(a);
		if (!ft_strcmp(ops[i], "rb") || !ft_strcmp(ops[i], "rr"))
			rotate(b);
		if (!ft_strcmp(ops[i], "rra") || !ft_strcmp(ops[i], "rrr"))
			reverse_rotate(a);
		if (!ft_strcmp(ops[i], "rrb") || !ft_strcmp(ops[i], "rrr"))
			reverse_rotate(b);
		free(ops[i]);
	}
	free(ops);
}
