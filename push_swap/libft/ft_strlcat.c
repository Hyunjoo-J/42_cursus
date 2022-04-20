/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:07:55 by hyjeong           #+#    #+#             */
/*   Updated: 2021/06/30 17:57:22 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	dst_len;
	size_t	result;
	size_t	i;

	dst_len = ft_strlen(dst);
	result = ft_strlen(src);
	i = 0;
	if (len <= dst_len)
		return (result + len);
	while (src[i] && i < (len - dst_len - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	result += dst_len;
	return (result);
}
