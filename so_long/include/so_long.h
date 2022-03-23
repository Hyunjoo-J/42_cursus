/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:14:49 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/23 21:18:49 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define BUFFER_SIZE 32

# define WP "assets/wall.xpm"
# define IP "assets/item.xpm"
# define EP "assets/exit.xpm"
# define FP "assets/floor.xpm"

# define TS 64

typedef struct	s_img
{
	void	*img;
	int	*data;
	int	size_l;
	int	bpp;
	int endian;
}	t_img;

typedef struct	s_scene
{
	int	map_width;
	int	map_height;
	char	**map;
	int	pos_x;
	int	pos_y;
	int num_item;
	int	num_exit;
	int	num_move;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_img	player_img[6];
	t_img	enemy_img[6];
	t_img	wall_img;
	t_img	item_img;
	t_img	exit_img;
	t_img	floor_img;
}	t_scene;

typedef struct s_gnl
{
	char			*temp;
	char			buf[BUFFER_SIZE + 1];
	int				cur_read;
	int				new_idx;
}	t_gnl;


int	get_next_line(int fd, char **line);

int check_ext(char *file, char *ext);
int	malloc_error(char **list, int i);
int	fill_image(t_scene *scene);

int	parse_map(char *file, t_scene *scene);

int	draw(t_scene *scene);
int	draw_init(t_scene *scene);

int	close_scene(t_scene *scene);
int	press_key(int keycode, t_scene *scene);

void	destroy_scene(t_scene *scene);

#endif
