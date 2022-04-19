/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD:push_swap/libft/ft_memccpy.c
/*   By: suko <suko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:24:35 by suko              #+#    #+#             */
/*   Updated: 2021/06/22 00:26:07 by suko             ###   ########.fr       */
=======
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:06:33 by hyjeong           #+#    #+#             */
/*   Updated: 2022/04/16 17:06:39 by hyjeong          ###   ########.fr       */
>>>>>>> 68a3d98e2905d1367baf38962dc4fe25d21fc091:push_swap/srcs/sorter/main.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
<<<<<<< HEAD:push_swap/libft/ft_memccpy.c
	unsigned int	i;

	i = 0;
	while (i < n)
=======
	t_stack		*cpy;
	t_params	params;

	params = init_params(mem);
	cpy = cpy_stack(mem->a, mem, &params);
	bubble_sort_it(cpy);
	set_target_index_cpy(cpy);
	set_target_index(cpy);
	free_stack(cpy);
	set_keep(mem);
	push_keep_false_b(mem);
	while (!is_empty_stack(mem->b))
	{
		params.elem = mem->b->first;
		evaluate_actions(mem, &params);
		sort(mem, &params);
	}
	if (!(is_on_top(mem->a, smallest(mem->a))))
		bring_to_top(mem->a, smallest(mem->a), mem);
	if (is_empty_stack(mem->a))
		error(mem, 1, NULL, NULL);
	free_all(mem, NULL, NULL);
}

int	main(int argc, char **argv)
{
	t_mem	*mem;
	int		red_args;

	mem = init_mem();
	if (argc >= 2)
>>>>>>> 68a3d98e2905d1367baf38962dc4fe25d21fc091:push_swap/srcs/sorter/main.c
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)dst)[i] == (unsigned char)c)
			return ((void *)&((unsigned char *)dst)[i + 1]);
		i++;
	}
	return (0);
}
