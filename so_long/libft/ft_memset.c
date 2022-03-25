/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:46:21 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/25 18:46:23 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*buffer;

	i = 0;
	buffer = b;
	while (i < len)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	return (buffer);
}
