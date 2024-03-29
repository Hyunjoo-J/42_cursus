/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:06:29 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/26 17:06:31 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_map_info(t_parse_info *data)
{
	data->outline = TRUE;
	data->collectible = 0;
	data->exit = 0;
	data->player = 0;
	data->error = FALSE;
}

void	ft_check_inline(char c, t_parse_info *data)
{
	if (c == 'C')
		data->collectible++;
	else if (c == 'E')
		data->exit++;
	else if (c == 'P')
		data->player++;
	else if (c != '0' && c != '1')
		data->error = TRUE;
}

void	ft_check_line(char *line, t_parse_info *data, int index, int last_line)
{
	int	i;

	i = 0;
	if (index == 0 || last_line - index - 1 == 0)
	{
		while (line[i])
			if (line[i++] != '1')
				data->outline = FALSE;
	}
	else
	{
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			data->outline = FALSE;
		while (line[i])
			ft_check_inline(line[i++], data);
	}
}

void	ft_check_map(char **map)
{
	int				i;
	t_parse_info	*map_data;

	i = 0;
	map_data = malloc(sizeof(t_parse_info));
	if (!map_data)
		exit(EXIT_FAILURE);
	ft_init_map_info(map_data);
	if (map[0])
	{
		map_data->error = FALSE;
		map_data->line_len = ft_strlen(map[0]);
		while (map[i])
		{
			if ((int)ft_strlen(map[i]) != map_data->line_len)
				map_data->error = TRUE;
			ft_check_line(map[i], map_data, i, ft_strlen2d(map));
			i++;
		}
	}
	ft_control_map_data(map_data);
	free(map_data);
}
