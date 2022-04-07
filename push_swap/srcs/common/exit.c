/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:58:07 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/08 03:07:04 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	free_stack(t_stack *sta)
{
	t_s_elem	*elem;

	elem = sta->first;
	while (elem)
	{
		sta->first = sta->first->next;
		free(elem);
		elem = NULL;
		elem = sta->first;
	}
	free(sta);
	sta = NULL;
}

void	free_all(t_mem *mem, int *min_a, int *min_b)
{
	free_stack(mem->a);
	free_stack(mem->b);
	free(mem);
	mem = NULL;
	if (!min_a)
	{
		free(min_a);
		min_a = NULL;
	}
	if (!min_b)
	{
		free(min_b);
		min_b = NULL;
	}
	exit (EXIT_FAILURE);
}

void	error(t_mem *mem, int print_option, int *min_a, int *min_b)
{
	if (print_option == 1)
		write(2, "Error\n", 6);
	free_all(mem, min_a, min_b);
	exit (EXIT_FAILURE);
}