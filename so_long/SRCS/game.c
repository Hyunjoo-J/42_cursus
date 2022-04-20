/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:06:45 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/26 17:06:47 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(t_data *data, char *move)
{
	if (data->map2d[data->player->y - 1][data->player->x] != '1'
		&& !ft_strncmp(move, "up", 2))
		move_up(data);
	if (data->map2d[data->player->y + 1][data->player->x] != '1'
		&& !ft_strncmp(move, "down", 4))
		move_down(data);
	if (data->map2d[data->player->y][data->player->x - 1] != '1'
		&& !ft_strncmp(move, "left", 4))
		move_left(data);
	if (data->map2d[data->player->y][data->player->x + 1] != '1'
		&& !ft_strncmp(move, "right", 5))
		move_right(data);
	printf("Number of step : %d\n", data->player->step);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 13)
		ft_move(data, "up");
	if (keycode == 1)
		ft_move(data, "down");
	if (keycode == 0)
		ft_move(data, "left");
	if (keycode == 2)
		ft_move(data, "right");
	if (keycode == 53)
		ft_exit(data);
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx->win);
	exit(EXIT_SUCCESS);
}
