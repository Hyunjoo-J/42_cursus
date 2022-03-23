/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:14:47 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/23 20:51:31 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_scene(t_scene *scene)
{
	scene->map_width = 0;
	scene->map_height = 0;
	scene->pos_x = -1;
	scene->pos_y = -1;
	scene->num_item = 0;
	scene->num_exit = 0;
	scene->num_move = 0;
	scene->map = 0;
	scene->mlx = 0;
	return (0);
}

int	init_mlx(t_scene *scene)
{
	if ((scene->mlx = mlx_init()) == 0)
		return (-1);
	if ((scene->mlx_win = mlx_new_window(scene->mlx,\
	scene->map_width * TS, scene->map_height * TS, "SO LONG")) == 0)
		return (-1);
	if ((scene->img.img = mlx_new_image(scene->mlx,\
	scene->map_width * TS, scene->map_height * TS)) == 0)
		return (-1);
	scene->img.data = (int *)mlx_get_data_addr(scene->img.img,\
	&scene->img.bpp, &scene->img.size_l, &scene->img.endian);
	if (fill_image(scene))
		return (-1);
	return (0);
}

void	destroy_scene(t_scene *scene)
{
	int	i;

	i = -1;
	while (scene->map != 0 && ++i < scene->map_height)
		free(scene->map[i]);
	if (scene->map != 0)
		free(scene->map);
	if (scene->mlx != 0 && scene->mlx_win != 0)
		mlx_destroy_window(scene->mlx, scene->mlx_win);
	if (scene->mlx != 0 && scene->wall_img.img != 0)
		mlx_destroy_image(scene->mlx, scene->wall_img.img);
	if (scene->mlx != 0 && scene->item_img.img != 0)
		mlx_destroy_image(scene->mlx, scene->item_img.img);
	if (scene->mlx != 0 && scene->exit_img.img != 0)
		mlx_destroy_image(scene->mlx, scene->exit_img.img);
	if (scene->mlx != 0 && scene->floor_img.img != 0)
		mlx_destroy_image(scene->mlx, scene->floor_img.img);
	i = -1;
	while (scene->mlx != 0 && ++i < 6)
	{
		if (scene->player_img[i].img != 0)
			mlx_destroy_image(scene->mlx, scene->player_img[i].img);
		if (scene->enemy_img[i].img != 0)
			mlx_destroy_image(scene->mlx, scene->enemy_img[i].img);
	}
}

int	main(int argc, char **argv)
{
	t_scene scene;

	if (init_scene(&scene))
		ft_putendl_fd("Error : initialization failed", 1);
	else if ((argc != 2) || check_ext(argv[1], ".ber") || parse_map(argv[1], &scene))
		ft_putendl_fd("Error : invalid input", 1);
	else if (init_mlx(&scene))
		ft_putendl_fd("Error : mlx initialization failed", 1);
	else
	{
		draw_init(&scene);
		mlx_hook(scene.mlx_win, 2, 1L << 0, press_key, &scene);
		mlx_loop_hook(scene.mlx, &draw, &scene);
		mlx_hook(scene.mlx_win, 17, 1L << 5, close_scene, &scene);
		mlx_loop(scene.mlx);
	}
	destroy_scene(&scene);
	exit(0);
}
