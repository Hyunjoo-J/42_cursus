/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:03:08 by hyjeong           #+#    #+#             */
/*   Updated: 2021/06/30 18:02:37 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	size_t	i;

	if (dst == 0 && src == 0)
	{
		return (dst);
	}
	i = 0;
	while (i < num)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dst);
}
