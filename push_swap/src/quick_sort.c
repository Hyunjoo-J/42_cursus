/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:31:23 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/20 17:53:46 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	quick_rec(t_stack *a, t_stack *b, int count, t_order *ords)
{
	int	i;

	if (is_sorted(a, count / 2 + count % 2, 0) != 0)
		quick_sort_a(a, b, count / 2 + count % 2, ords);
	if (is_sorted(b, count / 2, 1) != 0)
		quick_sort_b(a, b, count / 2, ords);
	else
	{
		i = -1;
		while (++i < count / 2)
			print_and_do(a, b, ft_split("pa", ' '), ords);
	}
}

void	le_three_sort_a_p(t_stack *a, t_stack *b, int count, t_order *ords)
{
	if (count == 2 && is_sorted(a, count, 0) != 0)
		print_and_do(a, b, ft_split("sa", ' '), ords);
	else if (count == 3)
	{
		if (get_value(a, 0) < get_value(a, 2) && \
		get_value(a, 2) < get_value(a, 1))
			print_and_do(a, b, ft_split("ra sa rra", ' '), ords);
		else if (get_value(a, 1) < get_value(a, 0) && \
		get_value(a, 0) < get_value(a, 2))
			print_and_do(a, b, ft_split("sa", ' '), ords);
		else if (get_value(a, 2) < get_value(a, 0) && \
		get_value(a, 0) < get_value(a, 1))
			print_and_do(a, b, ft_split("ra sa rra sa", ' '), ords);
		else if (get_value(a, 1) < get_value(a, 2) && \
		get_value(a, 2) < get_value(a, 0))
			print_and_do(a, b, ft_split("sa ra sa rra", ' '), ords);
		else if (get_value(a, 2) < get_value(a, 1) && \
		get_value(a, 1) < get_value(a, 0))
			print_and_do(a, b, ft_split("sa ra sa rra sa", ' '), ords);
	}
}

void	quick_sort_helper(int *i, int *rot)
{
	*i = -1;
	*rot = 0;
}

void	quick_sort_b(t_stack *a, t_stack *b, int count, t_order *ords)
{
	int		med;
	int		i;
	int		rot;
	t_stack	*temp;
	t_stack	*curr;

	if (count <= 3)
		return (le_three_sort_b(a, b, count, ords));
	curr = b->next;
	quick_sort_helper(&i, &rot);
	med = get_median(b, count);
	while (curr != 0 && ++i < count)
	{
		temp = curr;
		curr = curr->next;
		if (temp->val >= med)
		{
			while (b->next != 0 && b->next->val != temp->val && ++rot)
				print_and_do(a, b, ft_split("rb", ' '), ords);
			print_and_do(a, b, ft_split("pa", ' '), ords);
		}
	}
	while (get_count(b) != count / 2 && rot-- > 0)
		print_and_do(a, b, ft_split("rrb", ' '), ords);
	quick_rec(a, b, count, ords);
}

void	quick_sort_a(t_stack *a, t_stack *b, int count, t_order *ords)
{
	int		med;
	int		i;
	int		rot;
	t_stack	*temp;
	t_stack	*curr;

	if (count <= 3)
		return (le_three_sort_a(a, b, count, ords));
	med = get_median(a, count);
	curr = a->next;
	quick_sort_helper(&i, &rot);
	while (curr != 0 && ++i < count)
	{
		temp = curr;
		curr = curr->next;
		if (temp->val < med)
		{
			while (a->next != 0 && a->next->val != temp->val && ++rot)
				print_and_do(a, b, ft_split("ra", ' '), ords);
			print_and_do(a, b, ft_split("pb", ' '), ords);
		}
	}
	while (get_count(a) != count / 2 + count % 2 && rot-- > 0)
		print_and_do(a, b, ft_split("rra", ' '), ords);
	quick_rec(a, b, count, ords);
}
