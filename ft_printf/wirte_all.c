/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wirte_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:04:56 by hyunjoo           #+#    #+#             */
/*   Updated: 2021/10/30 20:59:37 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*write_s(char *s, t_flag **f, int **len)
{
	char	*ns;

	if (s == 0)
		s = "(null)";
	ns = ft_strdup(s);//새로운 메모리에 할당 복사
	if (!ns)
		return (0);
	while (s[(*f)->space] == ' ')
		((*f)->space)++;
	if (((*f)->pre) || ((*f)->dot))
		format_pres(&ns, (*f)->pre);
	if ((*f)->dig)
		format_width(&ns, (*f)->dig);
	if ((*f)->minus)
		format_minus(&ns, (*f)->space);
	if ((*f)->zero)
		format_zero(&ns, 's');
	(**len) += write(1, ns, ft_strlen(ns));
	free(ns);
	return (0);
}

void write_c(char c, t_flag **flag, int **len)
{
	if (((*flag)->dot) && (!(*flag)->pre))
		return (0);
	if ((*flag)->minus)
	{
		(**len) += write(1, &c, 1);
		while ((((*flag)->dig)--) && (((*flag)->dig) > 0))
			(**len) += write(1, " ", 1);
	}
	else
	{
		while ((((*flag)->dig)--) && (((*flag)->dig) > 0))
			(**len) += write(1, " ", 1);
		(**len) += write(1, &c, 1);
	}
	return (0);
}

void write_p(unsigned long num, t_flag **flag, int **len)
{
	char	*ns;
	int		x;

	x = 0;
	ns = ft_ulxtoa(num);
	if (!ns)
		return (0);
	if ((*flag)->pre)
		format_presnum(&ns, (*flag)->pre);
	format_hash(&ns, 'x');
	if ((*flag)->dig)
		format_width(&ns, (*flag)->dig);
	if (((*flag)->zero) && (!((*flag)->minus)) && (!((*flag)->pre)))
		format_zero(&ns, 'x');
	(((*flag)->minus) && format_minus(&ns, 0));
	(**len) += write(1, ns, ft_strlen(ns));
	free(ns);
	return (0);
}

void write_d(int num, t_flag **flag, int **len)
{
	char	*ns;

	if ((num == 0) && ((*flag)->dot) && (!(*flag)->pre))
	{
		while ((((*flag)->dig)--) && (((*flag)->dig) > -1))
			(**len) += write(1, " ", 1);
		return (0);
	}
	ns = ft_itoa(num);
	remove_sign(&ns);
	if (((*flag)->wspace) && (num >= 0))
	{
		(**len) += write(1, " ", 1);
		((*flag)->dig)--;
	}
	((((*flag)->pre) > 0) && format_presnum(&ns, (*flag)->pre));
	return_sign(&ns, num, (*flag)->plus);
	if ((*flag)->dig > 0)
		format_width(&ns, (*flag)->dig);
	if (((*flag)->zero) && (!((*flag)->minus)) && (!((*flag)->pre)))
		format_zero(&ns, 'd');
	(((*flag)->minus) && format_minus(&ns, 0));
	(**len) += write(1, ns, ft_strlen(ns));
	free(ns);
	return (0);
}

void write_u(unsigned int num, t_flag **flag, int **len)
{
	char	*ns;

	if ((num == 0) && ((*flag)->dot) && (!(*flag)->pre))
	{
		while ((((*flag)->dig)--) && (((*flag)->dig) > -1))
			(**len) += write(1, " ", 1);
		return (0);
	}
	ns = ft_uitoa(num);
	if ((*flag)->pre)
		format_presnum(&ns, (*flag)->pre);
	if ((*flag)->dig)
		format_width(&ns, (*flag)->dig);
	if (((*flag)->zero) && (!((*flag)->minus)) && (!((*flag)->pre)))
		format_zero(&ns, 's');
	(((*flag)->minus) && format_minus(&ns, 0));
	(**len) += write(1, ns, ft_strlen(ns));
	free(ns);
	return (0);
}
void write_x();