/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:06:54 by hyjeong           #+#    #+#             */
/*   Updated: 2021/07/06 17:00:44 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return ((char *)s1);
	start = 0;
	while (s1[start] && in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && in_set(s1[end], set))
		end--;
	new = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!new)
		return (0);
	i = 0;
	while (start <= end)
	{
		new[i] = s1[start];
		i++;
		start++;
	}
	new[i] = 0;
	return (new);
}
