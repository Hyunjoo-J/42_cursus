/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:14:47 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/22 21:43:56 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		retrun (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene scene;

	if (init_scene(&scene))
		ft_putendl_fd("Error : initialization failed", 1);
	else if (argc != 2 || check_ext(argv[1], "ber") || parse_map(argv[1], &scene))
		ft_putendl_fd("Error : invalid input", 1);
	else if (init_mlx(&scene))
		ft_putendl_fd("Error : mlx initialization failed", 1);
	else
	{
		draw_init(&scene);
	}
}