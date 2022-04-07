/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:53:35 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/08 03:28:03 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool	is_empty_stack(t_stack *sta)
{
	if (sta->first == NULL)
		retrun (true);
	return (false);
}

int	stack_length(t_stack *sta)
{
	int	length;
	t_s_elem	*elem;

	if (!sta)
		return (0);
	length = 0;
	elem = sta->first;
	while (elem)
	{
		length++;
		elem = elem->next;
	}
	return (length);
}

t_mem	*init_mem(void)
{
	t_mem	*mem;
	t_stack	*a;
	t_stack	*b;
	
	mem = (t_mem *)malloc(sizeof(t_mem));
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!mem || !a || !b)
		exit (EXIT_FAILURE);
	a->first = NULL;
	b->first = NULL;
	mem->action_count = 0;
	mem->a = a;
	mem->b = b;
	return (mem);
}

int	push_args(char *str, t_mem *mem, int *args)
{
	long	x;
	bool	space;

	space = true;
	while (*str)
	{
		if (space && *str != ' ')
		{
			x = push_atoi(str, mem);
			if (x > INT_MAX || x < INT_MIN)
				error(mem, 1, NULL, NULL);
			push_end(mem->a, x, mem);
			(*args)++;
			check_duplicates(mem);
		}
		space = *str == ' ';
		str++;
	}
	return (SUCCESS);
}

int	read_args(int argc, char **argv, t_mem *mem)
{
	int	args;
	int	i;

	i = 1;
	args = 0;
	while (i < argc)
	{
		push_args(argv[i], mem, &args);
		i++;
	}
	if (!(mem->a->first))
		error(mem, 0, NULL, NULL);
	return (args);
}