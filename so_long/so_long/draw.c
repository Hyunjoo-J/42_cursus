/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:14:36 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/23 17:43:56 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_scene *scene, int y, int x, t_img data)
{
	int	i;
	int	j;

	i = -1;
	y *= TS;
	x *= TS;
	while (++i < TS)
	{
		j = -1;
		while (++j < TS)
		{
			scene->img.data[(y + i) * TS * scene->map_width + x + j] =\
			data.data[(int)(i / (TS / 16.0)) * 16 + (int)(j / (TS / 16.0))];
		}
	}
}

int	draw_init(t_scene *scene)
{
	int	i;
	int	j;

	i = -1;
	while (++i < scene->map_height)
	{
		j = -1;
		while (++j < scene->map_width)
			draw_tile(scene, i, j, scene->floor_img);
	}
	mlx_put_image_to_window(scene->mlx, scene->mlx_win, scene->img.img, 0, 0);
	return (0);
}

int	draw(t_scene *scene)
{
	int	i;
	int	j;

	i = -1;
	while (++i < scene->map_height)
	{
		j = -1;
		while (++j < scene->map_width)
		{
			draw_tile(scene, i, j, scene->floor_img);
			if (i == scene->pos_y && j == scene->pos_x)
				draw_tile(scene, i, j, scene->player_img[0]);
			else if (scene->map[i][j] == '1')
				draw_tile(scene, i, j, scene->wall_img);
			else if (scene->map[i][j] == 'C')
				draw_tile(scene, i, j, scene->item_img);
			else if (scene->map[i][j] == 'E')
				draw_tile(scene, i, j, scene->exit_img);
		}
	}
	mlx_put_image_to_window(scene->mlx, scene->mlx_win, scene->img.img, 0, 0);
	return (0);
}
