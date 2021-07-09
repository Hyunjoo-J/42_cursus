/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:59:38 by hyjeong           #+#    #+#             */
/*   Updated: 2021/07/09 15:43:38 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_isincluded(char const *s, char c)
{
	unsigned int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static	char	**ft_free(char ***result, unsigned int count)
{
	unsigned int	i;

	if (*result == 0)
		return (0);
	i = count;
	while (i != 0)
	{
		free((*result)[--i]);
	}
	free(*result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	i;
	unsigned int	count;
	unsigned int	j;

	if (s == 0)
		return (0);
	result = malloc(sizeof(char *) * (ft_isincluded(s, c) + 1));
	if (result == 0 || s == 0)
		 return (ft_free(&result, 2));
	i = -1;
	count = 0;
	while (s[++i] != '\0')
	{
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (j != i)
		{
			result[count] = ft_substr(s, j, (i--) - j);
			count++;
		}
	}
	result[count] = 0;
	return (result);
}
