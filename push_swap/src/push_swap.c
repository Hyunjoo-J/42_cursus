/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:31:16 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/20 17:21:42 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
	c == '\f' || c == '\r' || c == ' ')
		return (0);
	else
		return (-1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*next;

	curr = stack;
	while (curr != 0)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void	push_swap(t_stack *a, t_stack *b, int count)
{
	t_order	*orders;

	orders = (t_order *)malloc(sizeof(t_order));
	orders->prev = 0;
	orders->next = 0;
	if (is_sorted(a, count, 0) == 0)
		return ;
	if (count <= 3)
		le_three_sort_a(a, b, count, orders);
	else
		quick_sort_a(a, b, count, orders);
	print_orders(orders);
	free_order(orders);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		count;

	count = get_input_count(argc, argv);
	if (count == -1)
		ft_putstr_fd("Error\n", 1);
	if (count <= 1)
		return (0);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->prev = 0;
	b->prev = 0;
	b->next = 0;
	fill_array(a, argv, argc);
	if (check_duplicate(a) == -1)
		ft_putstr_fd("Error\n", 1);
	else
		push_swap(a, b, count);
	free_stack(a);
	free_stack(b);
}
