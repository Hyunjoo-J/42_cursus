/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:27:20 by hyjeong           #+#    #+#             */
/*   Updated: 2021/07/06 17:40:50 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t num)
{
	unsigned char	*tmp_ptr;
	unsigned char	find;
	unsigned int	i;

	tmp_ptr = (unsigned char *)ptr;
	find = (unsigned char)c;
	i = 0;
	while (i < num)
	{
		if (tmp_ptr[i] == find)
			return (&tmp_ptr[i]);
		i++;
	}
	return (0);
}
