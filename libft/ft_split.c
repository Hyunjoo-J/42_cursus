/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:59:38 by hyjeong           #+#    #+#             */
/*   Updated: 2021/07/06 17:48:14 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*copy;

	if (!src || n <= 0)
		return (0);
	copy = (char *)malloc(sizeof(char) * (n + 1));
	if (!copy)
		return (0);
	i = 0;
	while (i < n)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

size_t	word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**ret;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!s)
		return (0);
	ret = (char **)malloc(sizeof(char *) * (word(s, c) + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (s[j] && i < ft_strlen(s))
	{
		k = 0;
		if (s[j] != c)
		{
			while (s[j + k] != c && s[j + k])
				k++;
			ret[i++] = ft_strndup((char *)s + j, k);
		}
		j += k + 1;
	}
	ret[i] = 0;
	return (ret);
}
