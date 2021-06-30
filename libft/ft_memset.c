/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:29:56 by hyjeong           #+#    #+#             */
/*   Updated: 2021/06/30 18:02:17 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char 	*temp;
	size_t			i;

	temp = ptr;
	i = 0;
	while (i < num)
	{
		temp[i] = value;
		i++;
	}
	return (ptr);
}
