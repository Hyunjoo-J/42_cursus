/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:02:56 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/25 18:03:03 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_fill_str(char *str, char *s1, char*s2)
{
	int		i;

	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
	{
		if (*s2 == '\n')
		{
			str[i++] = *s2++;
			break ;
		}
		str[i++] = *s2++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	str = ft_fill_str(str, s1, s2);
	free(s1);
	return (str);
}

int	ft_end_of_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
