/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:39:11 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/09 23:39:12 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
=======
#include "./includes/minishell.h"

>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
void	free_str(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

void	init_str(char **strs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		strs[i] = 0;
		i++;
	}
}

void	free_list(t_list **list)
{
	t_list	*item;

	if (*list)
	{
		while (*list)
		{
			item = *list;
			*list = (*list)->next;
			delete_item(item);
		}
		free(*list);
	}
}

void	free_all(t_info *info)
<<<<<<< HEAD
{
	if (info->home)
		free(info->home);
	if (info->pwd)
		free(info->pwd);
	free_list(&(info->env_list));
	free_list(&(info->export_list));
	free_list(&(info->user_list));
	/*if (!info->env_list && !info->export_list && !info->user_list)
		printf("!!\n");*/
=======
{
	if (info->bundles)
		free(info->bundles);
	if (info->pids)
		free(info->pids);
	free_list(&(info->env_list));
}

void	free_exit(t_info *info)
{
	free_all(info);
	exit(1);
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
}