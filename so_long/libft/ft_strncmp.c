/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:47:42 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/25 18:47:43 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*buff1;
	unsigned char	*buff2;

	i = 0;
	buff1 = (unsigned char *)s1;
	buff2 = (unsigned char *)s2;
	while (i < n && (buff1[i] || buff2[i]))
	{
		if (buff1[i] != buff2[i])
			return (buff1[i] - buff2[i]);
		i++;
	}
	return (0);
}
