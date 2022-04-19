/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:02:08 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/16 17:23:22 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool	is_empty_stack(t_stack *sta)
{
	if (sta->first == NULL)
		return (true);
	return (false);
}

int	stack_length(t_stack *sta)
{
	int			length;
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

int	push_args(char *string, t_mem *mem, int *args)
{
	long	x;
	bool	space;

	space = true;
	while (*string)
	{
		if (space && *string != ' ')
		{
			x = push_atoi(string, mem);
			if (x > INT_MAX || x < INT_MIN)
				error(mem, 1, NULL, NULL);
			push_end(mem->a, x, mem);
			(*args)++;
			check_duplicates(mem);
		}
		space = *string == ' ';
		string++;
	}
	return (SUCCESS);
}

int	read_args(int argc, char **argv, t_mem *mem)
{
	int		args;
	int		i;

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
