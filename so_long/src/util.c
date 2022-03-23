/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:25:12 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/23 20:52:15 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		check_ext(char *file, char *ext)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
		i++;
	if (i > 3 && !ft_strncmp(&(file[i - 4]), ext, 4))
		return (0);
	else
		return (-1);
}

int	malloc_error(char **list, int i)
{
	while (--i >= 0)
		free(list[i]);
	free(list);
	return (-1);
}

int	initialize_images(t_scene *scene)
{
	int	i;

	scene->wall_img.img = 0;
	scene->item_img.img = 0;
	scene->exit_img.img = 0;
	scene->floor_img.img = 0;
	i = -1;
	while (++i < 6)
	{
		scene->player_img[i].img = 0;
		scene->enemy_img[i].img = 0;
	}
	return (0);
}

void	get_img_addr(t_scene *scene)
{
	int	i;

	scene->wall_img.data = (int *)mlx_get_data_addr(scene->wall_img.img,\
	&scene->wall_img.bpp, &scene->wall_img.size_l, &scene->wall_img.endian);
	scene->item_img.data = (int *)mlx_get_data_addr(scene->item_img.img,\
	&scene->item_img.bpp, &scene->item_img.size_l, &scene->item_img.endian);
	scene->exit_img.data = (int *)mlx_get_data_addr(scene->exit_img.img,\
	&scene->exit_img.bpp, &scene->exit_img.size_l, &scene->exit_img.endian);
	scene->floor_img.data = (int *)mlx_get_data_addr(scene->floor_img.img,\
	&scene->floor_img.bpp, &scene->floor_img.size_l, &scene->floor_img.endian);
	i = -1;
	while (++i < 6)
	{
		scene->player_img[i].data = (int *)mlx_get_data_addr(\
		scene->player_img[i].img, &scene->player_img[i].bpp,\
		&scene->player_img[i].size_l, &scene->player_img[i].endian);
	}
}

int	fill_image(t_scene *scene)
{
	int	i;
	int	ts;
	char	p_file[14];
	char	e_file[14];

	initialize_images(scene);
	ts = TS;
	scene->wall_img.img = mlx_xpm_file_to_image(scene->mlx, WP, &ts, &ts);
	scene->item_img.img = mlx_xpm_file_to_image(scene->mlx, IP, &ts, &ts);
	scene->exit_img.img = mlx_xpm_file_to_image(scene->mlx, EP, &ts, &ts);
	scene->floor_img.img = mlx_xpm_file_to_image(scene->mlx, FP, &ts, &ts);
	if (!scene->wall_img.img || !scene->item_img.img ||\
	!scene->exit_img.img || !scene->floor_img.img)
		return (-1);
	i = -1;
	ft_strlcpy(p_file, "asset/p/.xpm", 14);
	while (++i < 6 && (++p_file[8]) < '6' && (++e_file[8]) < '6')
	{
		scene->player_img[i].img = mlx_xpm_file_to_image(scene->mlx,\
		p_file, &ts, &ts);
		if (!scene->player_img[i].img)
			return (-1);
	}
	get_img_addr(scene);
	return (0);
}
