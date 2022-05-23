/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:16:36 by hyjeong           #+#    #+#             */
/*   Updated: 2021/06/30 18:07:40 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t num)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	size_t			i;

	temp_dst = dst;
	temp_src = (unsigned char *)src;
	i = 0;
	while (i < num)
	{
		temp_dst[i] = temp_src[i];
		if (temp_src[i] == (unsigned char)c)
		{
			return (&dst[i + 1]);
		}
		i++;
	}
	return (0);
}
