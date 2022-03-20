/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:35:12 by hyjeong           #+#    #+#             */
/*   Updated: 2021/07/07 19:50:06 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*mem;

	mem = malloc(num * size);
	if (!mem)
	{
		return (NULL);
	}
	ft_bzero(mem, (num * size));
	return (mem);
}
