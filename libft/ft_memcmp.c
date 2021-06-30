/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:28:50 by hyjeong           #+#    #+#             */
/*   Updated: 2021/06/30 15:40:20 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t num)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	unsigned int	i;

	temp_s1 = (unsigned char*)s1;
	temp_s2 = (unsigned char*)s2;
	i = 0;
	while (i < num)
	{
		if (temp_s1[i] != temp_s2[i])
			return (temp_s1[i] - temp_s2[i]);
		i++;
	}
	return (0);
}
