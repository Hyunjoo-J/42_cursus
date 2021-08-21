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

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (temp == NULL)
		return(NULL);
	while(src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		s1_len;
	int		s2_len;
	int		i;

	if (!*s1 || !*s2)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new == 0)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		new[i] = s2[i - s1_len];
		i++;
	}
	new[i] = 0;
	return (new);
}

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
