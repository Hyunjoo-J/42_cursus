/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:23:07 by hyjeong           #+#    #+#             */
/*   Updated: 2021/07/06 20:29:19 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	unsigned int	i;

	if (!dst && !src)
		return (dst);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (dst < src)
	{
		while (i++ < num)
		{
			tmp_dst[i - 1] = tmp_src[i - 1];
		}
	}
	else
	{
		while (i < num)
		{
			tmp_dst[num - 1 - i] = tmp_src[num - 1 - i];
			i++;
		}
	}
	return (dst);
}
