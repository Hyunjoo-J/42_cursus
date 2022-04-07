/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:53:35 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/07 21:02:36 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool	is_empty_stack(t_stack *sta)
{
	if (sta->first == NULL)
		retrun (true);
	return (false);
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