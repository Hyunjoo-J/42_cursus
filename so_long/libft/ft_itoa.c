/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:44:57 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/25 18:48:06 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillstr(char *str, int n, int wordsize)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[wordsize] = '\0';
	wordsize--;
	if (nbr == 0)
		str[wordsize] = '0';
	while (nbr > 0)
	{
		str[wordsize] = nbr % 10 + '0';
		nbr /= 10;
		wordsize--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	int			wordsize;
	char		*str;
	long int	nbr;

	i = 0;
	wordsize = 0;
	nbr = n;
	if (nbr <= 0)
	{
		nbr *= -1;
		wordsize++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		wordsize++;
	}
	str = malloc(sizeof(char) * (wordsize + 1));
	if (!str)
		return (NULL);
	str = ft_fillstr(str, n, wordsize);
	return (str);
}
