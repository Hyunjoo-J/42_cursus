/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:30:33 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/20 04:30:37 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_all_digit(char *str)
{
	int	i;
	int	empty;

	i = 0;
	empty = 0;
	while (str[i] != '\0')
	{
		while (!is_space(str[i]))
			i++;
		while (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] == '\0' && empty == 0)
			return (-1);
		else if (str[i] == '\0')
			break ;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (empty == 0)
				empty = 1;
			i++;
		}
	}
	return (0);
}

int		check_overflow(char *str)
{
	unsigned int	i;
	long			num;
	int				flag;

	i = 0;
	num = 0;
	flag = 0;
	while (is_space(str[i]))
		i++;
	if (str[i++] == '-')
	{
		if (flag == 1)
			flag = 0;
		else
			flag = 1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		if ((flag == 0 && num > INT_MAX) || (flag == 1 && num > -INT_MIN))
			return (-1);
		i++;
	}
	return (0);
}

int		get_input_count(int argc, char **argv)
{
	int		count;
	char	*temp;
	int		i;

	count = 0;
	i = 0;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) == 0 || is_all_digit(argv[i]) == -1)
			return (-1);
		temp = argv[i];
		while (*temp != '\0')
		{
			if (check_overflow(temp) == -1)
				return (-1);
			while (*temp == '+' || *temp == '-' || !is_space(*temp))
				temp++;
			if (*temp == '\0')
				break ;
			while (*temp >= '0' && *temp <= '9')
				temp++;
			count++;
		}
	}
	return (count);
}

void	fill_array(t_stack *a, char **argv, int argc, int i)
{
	char	*temp;
	t_stack *prev;
	t_stack	*curr;

	curr = a;
	while (++i < argc)
	{
		temp = argv[i];
		while (*temp != '\0' && temp != 0)
		{
			while (!is_space(*temp))
				temp++;
			if (*temp == '\0')
				break ;
			prev = curr;
			curr = (t_stack *)malloc(sizeof(t_stack));
			curr->prev = prev;
			prev->next = curr;
			curr->next = 0;
			curr->val = ft_atoi(temp);
			while (is_space(*temp) && *temp != '\0')
				temp++;
		}
	}
}

int		check_duplicate(t_stack *a)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = a->next;
	while (curr != 0)
	{
		temp = curr->next;
		while (temp != 0)
		{
			if (curr->val == temp->val)
				return (-1);
			temp = temp->next;
		}
		curr = curr->next;
	}
	return (0);
}
