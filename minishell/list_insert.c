/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:38:53 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/10 01:42:19 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	list_insert(t_list **list, t_list *item) //key=value만 들어옴 25줄 초과!
{
	t_list	*tmp;

	tmp = (*list);
	if (tmp)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->key, item->key) == 0)
			{
				tmp->value = ft_strdup(item->value);
				delete_item(item);
				break ;
			}
			tmp = tmp->next;
		}
		if (!tmp)
		{
			tmp = (*list);
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = item;
		}
	}
	else
		(*list) = item;
}

void	list_insert_for_export(t_list **list, t_list *item) //25줄 초과!!
{
	t_list	*tmp;

	tmp = (*list);
	if (tmp)
	{
		if (ft_strcmp(tmp->key, item->key) )
		while (tmp)
		{
			if (tmp == *list && ft_strcmp(tmp->key, item->key) > 0)
			{
				item->next = tmp;
				(*list) = item; 
				break ;
			}
			else if (ft_strcmp(tmp->key, item->key) < 0 && (!tmp->next || ft_strcmp(tmp->next->key, item->key) > 0))
			{
				item->next = tmp->next;
				tmp->next = item;
				break ;
			}
			tmp = tmp->next;
		}
		if (!tmp)
		{
			tmp = (*list);
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = item;
		}
	}
	else
		(*list) = item;
}