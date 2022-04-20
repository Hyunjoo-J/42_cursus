/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:31:04 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/20 16:58:52 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_order(t_order *orders)
{
	t_order	*curr;
	t_order	*next;

	curr = orders;
	while (curr != 0)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void	store(char *str, t_order *ords)
{
	t_order	*temp;
	t_order	*new;

	temp = ords;
	while (temp->next != 0)
		temp = temp->next;
	new = (t_order *)malloc(sizeof(t_order));
	new->next = 0;
	new->prev = temp;
	temp->next = new;
	ft_strlcpy(new->order, str, 5);
	if (new->order[1] == 'r')
	{
		new->order[0] = 'd';
		new->order[1] = new->order[2];
		new->order[2] = '\0';
	}
}

void	merge_orders(t_order *ords)
{
	t_order	*curr;
	t_order	*t;

	curr = ords;
	curr = curr->next;
	while (curr != 0)
	{
		t = curr->next;
		while (curr->order[0] != 'p' && t != 0 && t->order[0] != 'p' && \
		t->order[1] == curr->order[1])
			t = t->next;
		while (curr->order[0] != 'p' && t != 0 && t != curr)
		{
			if (t->order[0] == curr->order[0] && t->order[1] != curr->order[1])
			{
				curr->order[1] = curr->order[0];
				t->prev->next = t->next;
				t->next->prev = t->prev;
				free(t);
				break ;
			}
			t = t->prev;
		}
		curr = curr->next;
	}
}

void	compress_orders(t_order *ords)
{
	t_order	*curr;
	t_order	*temp;
	int		check;

	curr = ords->next;
	while (curr != 0)
	{
		temp = curr->next;
		while (curr->order[0] != 'k' && temp != 0)
		{
			check = check_compression(temp, curr);
			if (check == 1)
			{
				temp->order[0] = 'k';
				curr->order[0] = 'k';
				break ;
			}
			else if (check == -1)
				break ;
			temp = temp->next;
		}
		curr = curr->next;
	}
}

void	print_orders(t_order *ords)
{
	t_order	*temp;

	merge_orders(ords);
	compress_orders(ords);
	temp = ords->next;
	while (temp != 0)
	{
		if (temp->order[0] == 'd')
		{
			ft_putstr_fd("rr", 1);
			ft_putchar_fd(temp->order[1], 1);
			ft_putendl_fd("", 1);
		}
		else if (temp->order[0] != 'k')
			ft_putendl_fd(temp->order, 1);
		temp = temp->next;
	}
}
