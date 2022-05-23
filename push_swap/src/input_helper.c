/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:30:33 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/04/20 19:08:07 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == ' ')
			i++;
		else if (str[i] != '\0')
			return (-1);
	}
	return (0);
}

int	check_overflow(char *str)
{
	unsigned int	i;
	long			num;
	int				flag;

	i = 0;
	num = 0;
	flag = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return (-1);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (flag == 1 && str[i] == '-')
			flag = 0;
		else if (flag == 0 && str[i] == '-')
			flag = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - '0';
		if ((flag == 0 && num > INT_MAX) || (flag == 1 && num > -INT_MIN))
			return (-1);
	}
	return (0);
}

int	get_input_count(int argc, char **argv)
{
	int		count;
	char	*temp;
	int		i;

	count = 0;
	i = 0;
	while (++i < argc)
	{
		if (is_all_digit(argv[i]) == -1)
			return (-1);
		temp = argv[i];
		while (*temp != '\0')
		{
			if (check_overflow(temp) == -1)
				return (-1);
			while (*temp != ' ' && *temp != '\0')
				temp++;
			count++;
			if (*temp == ' ')
				temp++;
		}
	}
	return (count);
}

void	fill_array(t_stack *a, char **argv, int argc)
{
	char	*temp;
	int		i;
	t_stack	*prev;
	t_stack	*curr;

	i = 0;
	curr = a;
	while (++i < argc)
	{
		temp = argv[i];
		while (*temp != '\0')
		{
			prev = curr;
			curr = (t_stack *)malloc(sizeof(t_stack));
			curr->prev = prev;
			prev->next = curr;
			curr->next = 0;
			curr->val = ft_atoi(temp);
			while (*temp != ' ' && *temp != '\0')
				temp++;
			if (*temp == ' ')
				temp++;
		}
	}
	return ;
}

int	check_duplicate(t_stack *a)
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
