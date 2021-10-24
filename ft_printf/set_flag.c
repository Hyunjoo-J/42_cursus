/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:37:15 by hyunjoo           #+#    #+#             */
/*   Updated: 2021/10/25 01:26:21 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//여기서는 flag값들을 세팅하는데 그침
static void	reset_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->wspace = 0;
	flag->sharp = 0;
	flag->dig = 0;
	flag->pres = 0;
	flag->var_pres = 0;
	flag->var_width = 0;
	flag->space = 0;
	flag->dot = 0;
}

static void	set_dot(char *s, t_flag *flag)
{
	int	i;
	char	*dot;

	i = 0;
	dot = ft_strrchr(s, '.');
	if (dot)
	{
		flag->dot = 1;
		while(ft_isdigit(dot[i + 1]))
			(flag->pres) = (flag->pres) * 10 + (dot[++i] - 48);
	}
	i = 0;
	while (s[i] && !ft_isdigit(s[i]) && (s[i] != '.'))//dot앞에 있는 플래그들 확인 숫자가 나오거나 dot이 나오면 멈춤
		i++;
	if (s[i] == '0')
		flag->zero = 1;
	while (s[i] && ft_isdigit(s[i]))
		(flag->dig) = (flag->dig) * 10 + (s[++i] - 48);
}

void	set_flag(char *s, t_flag *flag)
{
	reset_flag(flag);//플래그 초기값 세팅
	set_dot(s, flag);
	while (*s != 0)
	{
		if (*s == '-')
			flag->minus = 1;
		else if (*s == '+')
			flag->plus = 1;
		else if (*s =='#')
			flag->sharp = 1;
		else if (*s == ' ' && (flag->plus) == 0)
			flag->wspace = 0;
		else if (*s == '*' && *(s - 1) == '.')
			flag->var_pres = 1;
		else if ((*s == '*') && (!(flag->dig)))
			flag->var_width = 1;
		else if ((*s == '0') && (!(flag->dig)) && (!(flag->pres)))
			flag->zero = 1;
		s++;
	}
}