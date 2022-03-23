/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:27:16 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/23 21:34:17 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_scene(t_scene *scene)
{
	destroy_scene(scene);
	exit(0);
}

int	move_player(t_scene *scene, int y, int x)
{
	if (scene->map[scene->pos_y + y][scene->pos_x + x] == '1')
		return (-1);
	if (scene->map[scene->pos_y + y][scene->pos_x + x] == 'E')
	{
		if (scene->num_item == 0)
		{
			ft_putnbr_fd(++(scene->num_move), 1);
			ft_putendl_fd("\nEscape!", 1);
			return (close_scene(scene));
		}
		else
			ft_putendl_fd("You're not ready to escape", 1);
	}
	else
	{
		scene->pos_y = scene->pos_y + y;
		scene->pos_x = scene->pos_x + x;
		ft_putnbr_fd(++(scene->num_move), 1);
		ft_putendl_fd("", 1);
		if (scene->map[scene->pos_y][scene->pos_x] == 'C' &&\
		(scene->num_item--) > 0)
			scene->map[scene->pos_y][scene->pos_x] = '0';
	}
	draw(scene);
	return (0);
}

int	press_key(int keycode, t_scene *scene)
{
	if (keycode == 13)
		move_player(scene, -1, 0);
	else if (keycode == 0)
		move_player(scene, 0, -1);
	else if (keycode == 1)
		move_player(scene, 1, 0);
	else if (keycode == 2)
		move_player(scene, 0, 1);
	else if (keycode == 53)
		return (close_scene(scene));
	else
	{
		ft_putnbr_fd(keycode, 1);
		ft_putendl_fd("noting\n", 1);
	}
	return (0);
}
