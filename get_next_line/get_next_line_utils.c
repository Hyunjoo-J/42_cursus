/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:12:16 by hyjeong           #+#    #+#             */
/*   Updated: 2021/08/21 02:12:16 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s && *(s + i) != '\0')
		i++;
	return (i);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + find_newline(s2) + 1 + 1));
	if (!str)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	ft_memcpy(str, s1, i);
	while (*(s2 + j) != '\0')
	{
		*(str + i + j) = *(s2 + j);
		j++;
		if (*(s2 + j - 1) == '\n')
			break ;
	}
	*(str + i + j) = '\0';
	free((void *)s1);
	return (str);
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;

	i = 0;
	ptr_src = (unsigned char *)src;
	ptr_dest = (unsigned char *)dest;
	if (ptr_src == ptr_dest)
		return (NULL);
	while (i < n)
	{
		*(ptr_dest + i) = *(ptr_src + i);
		i++;
	}
	return (dest);
}

size_t		find_newline(char const *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int			find_end(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}