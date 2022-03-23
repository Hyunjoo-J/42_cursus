/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:45:01 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/23 20:52:17 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		increase_map(t_scene *scene)
{
	int		i;
	int		j;
	char	**temp;

	temp = malloc(sizeof(char *) * (scene->map_height + 1));
	if (temp == 0)
		return (-1);
	i = -1;
	while (++i < scene->map_height)
	{
		j = -1;
		if ((temp[i] = malloc(sizeof(char) * scene->map_width)) == 0)
			return (malloc_error(temp, i));
		while (++j < scene->map_width)
			temp[i][j] = scene->map[i][j];
	}
	if ((temp[i] = malloc(sizeof(char) * scene->map_width)) == 0)
		return (malloc_error(temp, i));
	while (--i >= 0)
		free(scene->map[i]);
	free(scene->map);
	scene->map = temp;
	scene->map_height += 1;
	return (0);
}

void	fill_map(t_scene *scene, char *line)
{
	int	i;

	i = -1;
	while (++i < scene->map_width)
		scene->map[scene->map_height - 1][i] = line[i];
}

int		update_scene(t_scene *scene, int i, int j, char typ)
{
	if (typ == 'P' && scene->pos_x == -1)
	{
		scene->pos_y = i;
		scene->pos_x = j;
		scene->map[i][j] = '0';
	}
	else if (typ == 'C')
		scene->num_item++;
	else if (typ == 'E')
		scene->num_exit++;
	else if (typ != '1' && typ != '0')
		return (-1);
	return (0);
}

int		check_map(t_scene *scene)
{
	int	i;
	int	j;

	i = -1;
	while (++i < scene->map_height)
	{
		j = -1;
		while (++j < scene->map_width)
		{
			if (((i == 0 || i == (scene->map_height - 1) || j == 0 ||\
			j == (scene->map_width - 1)) && scene->map[i][j] != '1') ||\
			(scene->map[i][j] == 'P' && scene->pos_x != -1))
				return (-1);
			if (update_scene(scene, i, j, scene->map[i][j]))
				return (-1);
		}
	}
	if (scene->num_item == 0 || scene->num_exit == 0)
		return (-1);
	return (0);
}

int		parse_map(char *file, t_scene *scene)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (scene->map_width == 0)
			scene->map_width = ft_strlen(line);
		if (scene->map_width != (int)ft_strlen(line) || increase_map(scene))
		{
			free(line);
			return (-1);
		}
		fill_map(scene, line);
		free(line);
		if (ret == 0)
			break ;
	}
	if (check_map(scene))
		return (-1);
	return (0);
}

