/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 00:21:58 by suko              #+#    #+#             */
/*   Updated: 2022/04/20 04:17:58 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_stack {
	struct s_stack		*prev;
	struct s_stack		*next;
	int					val;
}				t_stack;

typedef struct	s_order {
	struct s_order		*prev;
	struct s_order		*next;
	char				order[5];
}				t_order;

int				is_all_digit(char *str);
int				check_overflow(char *str);
int				get_input_count(int argc, char **argv);
void			fill_array(t_stack *a, char **argv, int argc, int i);
int				check_duplicate(t_stack *a);

int				swap(t_stack *stack);
int				push(t_stack *from, t_stack *to);
int				rotate(t_stack *stack);
int				reverse_rotate(t_stack *stack);

int				get_count(t_stack *stack);
int				get_value(t_stack *stack, int index);
int				ft_strcmp(char *a, char *b);
void			print_and_do(t_stack *a, t_stack *b, char **ops, t_order *ords);
int				is_sorted(t_stack *stack, int count, int type);

void			le_three_sort_a(t_stack *a, t_stack *b, int count,\
				t_order *ords);
void			le_three_sort_b(t_stack *a, t_stack *b, int count,\
				t_order *ords);
int				get_median(t_stack *a, int count);

void			quick_sort_a(t_stack *a, t_stack *b, int count, t_order *ords, int i);
void			quick_sort_b(t_stack *a, t_stack *b, int count, t_order *ords, int i);
void			le_three_sort_a_p(t_stack *a, t_stack *b, int count,\
				t_order *ords);

void			free_order(t_order *orders);
void			store(char *str, t_order *orders);
void			print_orders(t_order *ords);

int				check_compression(t_order *temp, t_order *curr);
int				is_space(char c);

#endif
