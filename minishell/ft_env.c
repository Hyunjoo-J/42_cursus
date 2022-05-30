/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 02:41:25 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/05/31 04:26:46 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **command, t_info *info)
{
	t_list	*tmp;

	tmp = info->list;
	if (command[1] != 0)
	{
		printf("env: %s: No such file of directory\n", command[1]);
		return (127);//명령어의 경로($PATH) 문제 혹은 명령어 오타
	}
	/* 무엇과 비교해야하는지에 대한 생각
	while (ft_strcmp(tmp->value, 들어오는 인자))
		tmp = tmp->next;
	*/
	while (tmp)
	{
		if (tmp->print)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}