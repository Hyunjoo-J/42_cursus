/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:57:33 by hyjeong           #+#    #+#             */
/*   Updated: 2021/06/21 14:35:34 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	unsigned int i;

	i = 0;
	whlie (src[i] && i < len - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	retrun (i);
}
