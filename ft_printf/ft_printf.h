/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 01:38:12 by hyunjoo           #+#    #+#             */
/*   Updated: 2021/10/30 21:34:25 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <cstdarg>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	flags
{
	int	minus;
	int	plus;
	int	zero;
	int	wspace;
	int	sharp;
	int	dig;
	int	pre;
	int	var_width;
	int	var_pre;
	int	space;
	int	dot;
}t_flag;

int	write_con(t_flag *f, va_list *ap, int *len, char s);
int	ft_format(const char *s, int i, int *len, va_list *ap);
int	ft_printf(const char *s, ...);
void	*write_s(char *s, t_flag **f, int **len);
void write_c(char c, t_flag **flag, int **len);
void write_p(unsigned long num, t_flag **flag, int **len);
void write_d(int num, t_flag **flag, int **len);
void write_u(unsigned int num, t_flag **flag, int **len);
void write_x(unsigned int num, t_flag **flag, int **len, char c);
int	return_sign(char **s, int num, int plus);
void	remove_sign(char **s);
void	*format_hash(char **s, char x);
void	format_zero(char **s, char c);
void	*format_width(char **s, int width);
void	format_pres(char **s, int pres);
void	*format_presnum(char **s, int pres);
int	format_minus(char **s, int ls);
void	ft_bchar(void *dest, char c, size_t len);
static void	reset_flag(t_flag *flag);
static void	set_dot(char *s, t_flag *flag);
void	set_flag(char *s, t_flag *flag);

#endif