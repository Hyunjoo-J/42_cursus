/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:25:12 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/22 22:12:58 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_ext(char *file, char *ext)//지도 형식이 맞게 들어 왔는지 확인
{
	int	i;

	i = 0;
	while (file[i] != 0)//길이 재서 뒤에서 3글자만 확인
		i++;
	if (i > 3 && !ft_strncmp(&(file[i - 4]), ext, 4))
		return (0);
	else
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

int	fill_image(t_scene *scene)
{
	int	i;
	int	j;
	char	p_file[14];
	char	e_file[14];

	initialize_images(scene);
	ts = TS;
}