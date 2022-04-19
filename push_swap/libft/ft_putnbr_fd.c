/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suko <suko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:40:32 by suko              #+#    #+#             */
/*   Updated: 2021/06/22 00:26:54 by suko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_putnbr_fd(int n, int fd)
{
	char			rev[13];
	unsigned int	i;
	unsigned int	temp;

	i = 0;
	temp = (n < 0) ? (unsigned int)n * (-1) : (unsigned int)n;
	while (temp >= 1)
	{
		rev[i++] = temp % 10 + '0';
		temp = temp / 10;
	}
	if (n < 0)
		rev[i++] = '-';
	else if (n == 0)
		rev[i++] = '0';
	temp = 0;
	while (i > 0)
		write(fd, &rev[(i--) - 1], 1);
}
