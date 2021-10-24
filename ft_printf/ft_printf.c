/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:49:58 by hyunjoo           #+#    #+#             */
/*   Updated: 2021/10/25 01:26:24 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *s, int i, int *len, va_list *ap)
{
	char conversion;
	char *format;
	t_flag	f;
	char	flag[16];
	int	j;

	ft_bzero(flag, 16);
	format = "-+ #.*0123456789\n";
	while (ft_strchr(format, s[j]))
		j++;
	conversion = s[j];
	flag[j] = 0;//%#3d가 왔다면 j = 2, s[j]=d 따라서 flag 배열의 두칸만을 사용한다. 그렇기에 마지막칸을 flag[j = 2]를 null로 채워준다.
	while (j--)
		flag[j] = s[j];
	i = i + j + 1; //위의 예시 그대로에서 d까지 읽고 그 다음 문자를 확인하기 위함
	set_flag(flag, &f);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	len;
	va_list	ap;

	len = 0;
	va_start(ap, s);
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] == '%')
			i = ft_format(&s[i + 1], i + 1, &len, &ap);
		if (s[i] != 0)
			len += write(1, &s[i++], 1);
	}
	va_end(ap);
	return (len);
}
