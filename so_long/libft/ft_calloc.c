/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:44:25 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/25 18:44:27 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buff;
	size_t	i;

	i = count * size;
	buff = malloc(sizeof(char) * i);
	if (!buff)
		return (NULL);
	ft_bzero(buff, i);
	return (buff);
}
