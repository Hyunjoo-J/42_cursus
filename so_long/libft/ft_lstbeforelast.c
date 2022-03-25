/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbeforelast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:45:14 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/25 18:45:15 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstbeforelast(t_list *lst)
{
	t_list	*temp;
	t_list	*actual;

	temp = lst;
	actual = lst;
	while (temp->next)
	{
		actual = temp;
		temp = temp->next;
	}
	return (actual);
}
