/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:47:57 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/25 18:47:58 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_filltrim(char *trim, size_t start, size_t i, char const *s1)
{
	size_t	j;

	j = 0;
	while (start <= i)
		trim[j++] = s1[start++];
	trim[j] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	char	*trim;

	i = 0;
	start = 0;
	if (s1 == NULL)
		return (NULL);
	while (ft_isinset(s1[i], (char *)set))
		i++;
	start = i;
	if (i == ft_strlen(s1))
		return (ft_calloc(1, 1));
	while (s1[i])
		i++;
	i--;
	while (ft_isinset(s1[i], (char *)set))
		i--;
	trim = malloc(sizeof(char) * (i - start + 2));
	if (!trim)
		return (NULL);
	trim = ft_filltrim(trim, start, i, s1);
	return (trim);
}
