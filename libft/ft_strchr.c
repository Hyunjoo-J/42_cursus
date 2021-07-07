/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:36:40 by hyjeong           #+#    #+#             */
/*   Updated: 2021/07/07 17:24:34 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	char	find;
	int		i;

	find = (unsigned int)character;
	i = 0;
	while (str[i])
	{
		if (str[i] == find)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (str[i] == find)
	{
		return ((char *)str + i);
	}
	return (0);
}
