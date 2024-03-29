/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:07:18 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/26 17:07:19 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_data(t_data *data)
{
	t_mlx		*mlx;
	t_player	*player;
	t_img		*img;

	mlx = malloc(sizeof(t_mlx));
	player = malloc(sizeof(t_player));
	img = malloc(sizeof(t_img));
	if (!mlx || !player || !img)
		exit(EXIT_FAILURE);
	data->mlx = mlx;
	data->player = player;
	data->img = img;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	ft_init_data(data);
	data->map2d = ft_create_map(av[1]);
	ft_check_map(data->map2d);
	ft_map_info(data);
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, \
	ft_strlen(data->map2d[0]) * SIZE, \
	ft_strlen2d(data->map2d) * SIZE, "So Long");
	ft_print_map(data);
	mlx_hook(data->mlx->win, 2, 0, key_hook, data);
	mlx_hook(data->mlx->win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx->mlx);
	ft_split_clear(data->map2d);
	return (0);
}
