/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:16:36 by hyjeong           #+#    #+#             */
/*   Updated: 2022/02/24 02:03:31 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void* ft_memccpy(void* dst, const void* src, int c, size_t n)
{
	unsigned char* tmp;
	unsigned char* str;
	size_t i;

	tmp = (unsigned char*)dst;
	str = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = str[i];
		if (str[i] == (unsigned char)c)
			return ((void*)dst + i + 1);
		i++;
	}
	return (0);
}
