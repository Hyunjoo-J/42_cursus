/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_all2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:59:49 by hyunjoo           #+#    #+#             */
/*   Updated: 2021/10/30 21:01:58 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void write_x(unsigned int num, t_flag **flag, int **len, char c)
{
	char	*ns;
	int		x;

	x = 0;
	if (c == 'X')
		x = 1;
	if ((num == 0) && ((*flag)->dot) && (!(*flag)->pre))
	{
		while ((((*flag)->dig)--) && (((*flag)->dig) > -1))
			(**len) += write(1, " ", 1);
		return (0);
	}
	ns = ft_uxtoa(num, x);
	if (!ns)
		return (0);
	((((*flag)->pre) > 0) && format_presnum(&ns, (*flag)->pre));
	((((*flag)->sharp) > 0) && (num != 0) && format_hash(&ns, c));
	if ((*flag)->dig)
		format_width(&ns, (*flag)->dig);
	if (((*flag)->zero) && (!((*flag)->minus)) && (!((*flag)->pre)))
		format_zero(&ns, c);
	(((*flag)->minus) && format_minus(&ns, 0));
	(**len) += write(1, ns, ft_strlen(ns));
	free(ns);
	return (0);
}

int	return_sign(char **s, int num, int plus)
{
	char	*ns;
	char	*temp;
	char	sign;
	int		len;

	if (num >= 0)
		sign = '+';
	else
		sign = '-';
	if ((num < 0) || plus)
	{
		len = ft_strlen(*s);
		temp = *s;
		ns = malloc(len + 2);
		ns[0] = sign;
		ns[len + 1] = '\0';
		while (len--)
			ns[len + 1] = (*s)[len];
		*s = ns;
		free(temp);
	}
	return (0);
}

void	remove_sign(char **s)
{
	int		i;

	i = 0;
	if (((*s)[0]) == '-')
	{
		while ((*s)[i++])
			(*s)[i - 1] = (*s)[i];
		(*s)[i] = '\0';
	}
}

void	*format_hash(char **s, char x)
{
	int		len;
	char	*new_s;
	char	*temp;
	int		i;

	i = 2;
	len = ft_strlen(*s);
	temp = *s;
	new_s = malloc(len + 3);
	if (!new_s)
		return (0);
	new_s[0] = '0';
	new_s[1] = x;
	new_s[len + 2] = '\0';
	while (*((*s)++))
		new_s[(i++)] = *((*s) - 1);
	*s = new_s;
	free(temp);
	return (0);
}