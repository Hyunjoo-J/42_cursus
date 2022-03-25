/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:47:24 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/25 18:47:25 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_size;
	size_t	dest_size;

	i = 0;
	j = 0;
	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	if (dstsize == 0 || dstsize < dest_size)
		return (src_size + dstsize);
	if (src_size == 0)
		return (dest_size);
	while (dest[i])
	{
		i++;
	}
	while (src[j] && dest_size + j < dstsize - 1)
	{
		dest[dest_size + j] = src[j];
		j++;
	}
	dest[dest_size + j] = '\0';
	return (src_size + dest_size);
}
