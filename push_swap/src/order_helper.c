/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:39:47 by suko              #+#    #+#             */
/*   Updated: 2021/06/29 16:52:15 by suko             ###   ########.fr       */
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
	t_order *temp;
	t_order *new;

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
	t_order	*temp;

	curr = ords;
	while ((curr = curr->next) != 0)
	{
		temp = curr->next;
		while (curr->order[0] != 'p' && temp != 0 && temp->order[0] != 'p' &&\
		temp->order[1] == curr->order[1])
			temp = temp->next;
		while (curr->order[0] != 'p' && temp != 0 && temp != curr)
		{
			if (temp->order[0] == curr->order[0] &&\
			temp->order[1] != curr->order[1])
			{
				curr->order[1] = curr->order[0];
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				free(temp);
				break ;
			}
			temp = temp->prev;
		}
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