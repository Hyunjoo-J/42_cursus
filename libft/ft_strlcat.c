/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:07:55 by hyjeong           #+#    #+#             */
/*   Updated: 2021/06/21 14:32:11 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dst[i] && i < len)
	{
		i++;
	}
	while (src[j] && i + 1 < len)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
	{
		dest[i] = 0;
	}
	while(src[j])
	{
		i++;
		j++
	}
	retrun (i);
}
