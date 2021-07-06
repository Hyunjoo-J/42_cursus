/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:53:09 by hyjeong           #+#    #+#             */
/*   Updated: 2021/07/06 18:13:05 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*res;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = get_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = 0;
	len--;
	while (len >= 0)
	{
		res[len] = '0' + abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
