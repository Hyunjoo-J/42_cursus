/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:31:29 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/20 17:31:03 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	le_three_sort_b(t_stack *a, t_stack *b, int count, t_order *ords)
{
	if (count == 2 && is_sorted(b, count, 1) != 0)
		print_and_do(a, b, ft_split("sb pa", ' '), ords);
	else if (count == 2)
		print_and_do(a, b, ft_split("pa", ' '), ords);
	else if (count == 3)
	{
		if (get_value(b, 0) < get_value(b, 2) && \
		get_value(b, 2) < get_value(b, 1))
			print_and_do(a, b, ft_split("sb pa sb pa", ' '), ords);
		else if (get_value(b, 1) < get_value(b, 0) && \
		get_value(b, 0) < get_value(b, 2))
			print_and_do(a, b, ft_split("pa sb pa sa", ' '), ords);
		else if (get_value(b, 2) < get_value(b, 0) && \
		get_value(b, 0) < get_value(b, 1))
			print_and_do(a, b, ft_split("sb pa pa", ' '), ords);
		else if (get_value(b, 1) < get_value(b, 2) && \
		get_value(b, 2) < get_value(b, 0))
			print_and_do(a, b, ft_split("pa sb pa", ' '), ords);
		else if (get_value(b, 2) > get_value(b, 1) && \
		get_value(b, 1) > get_value(b, 0))
			print_and_do(a, b, ft_split("sb pa sb pa sa", ' '), ords);
		else
			print_and_do(a, b, ft_split("pa pa", ' '), ords);
	}
	print_and_do(a, b, ft_split("pa", ' '), ords);
}

void	le_three_sort_a(t_stack *a, t_stack *b, int count, t_order *ords)
{
	if (count == 2 && is_sorted(a, count, 0) != 0)
		print_and_do(a, b, ft_split("sa", ' '), ords);
	else if (count == 3)
	{
		if (get_count(a) > 3)
			le_three_sort_a_p(a, b, count, ords);
		else if (get_value(a, 0) < get_value(a, 2) && \
		get_value(a, 2) < get_value(a, 1))
			print_and_do(a, b, ft_split("rra sa", ' '), ords);
		else if (get_value(a, 1) < get_value(a, 0) && \
		get_value(a, 0) < get_value(a, 2))
			print_and_do(a, b, ft_split("sa", ' '), ords);
		else if (get_value(a, 2) < get_value(a, 0) && \
		get_value(a, 0) < get_value(a, 1))
			print_and_do(a, b, ft_split("rra", ' '), ords);
		else if (get_value(a, 1) < get_value(a, 2) && \
		get_value(a, 2) < get_value(a, 0))
			print_and_do(a, b, ft_split("ra", ' '), ords);
		else if (get_value(a, 2) < get_value(a, 1) && \
		get_value(a, 1) < get_value(a, 0))
			print_and_do(a, b, ft_split("ra sa", ' '), ords);
	}
}

int	partition(int *a, int start, int end)
{
	int	x;
	int	i;
	int	j;
	int	temp;

	x = a[end];
	i = start - 1;
	j = start - 1;
	while (++j < end)
	{
		if (a[j] < x)
		{
			i++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	a[end] = a[i + 1];
	a[i + 1] = x;
	return (i + 1);
}

void	real_quick_sort(int *a, int start, int end)
{
	int	q;

	if (start < end)
	{
		q = partition(a, start, end);
		real_quick_sort(a, start, q - 1);
		real_quick_sort(a, q + 1, end);
	}
}

int	get_median(t_stack *stack, int count)
{
	int		i;
	int		*list;
	t_stack	*curr;

	i = -1;
	list = (int *)malloc(sizeof(int) * count + 1);
	curr = stack->next;
	while (++i < count)
	{
		list[i] = curr->val;
		curr = curr->next;
	}
	real_quick_sort(list, 0, count - 1);
	return (list[count / 2]);
}
