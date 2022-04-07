/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:19:50 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/08 03:00:17 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	algorithm(t_mem *mem)
{
	
}

int	main(int argc, char **argv)
{
	t_mem	*mem;
	int		red_args;
	if (argc >= 2)
	{
		red_args = read_args(argc, argv, mem);
		if (is_empty_stack(mem->a))
			error(mem, 1, NULL, NULL);
		if (is_sorted_stack(mem->a))
			free_all(mem, NULL, NULL);
		if (red_args <= 5)
			small_cases(mem->a, mem->b, mem);
		else
			algorithm(mem);
	}
	error(mem, 0, NULL, NULL);
	return (0);
}