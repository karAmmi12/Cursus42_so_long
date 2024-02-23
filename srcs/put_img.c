/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:04:00 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 13:14:52 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// protection des images
void	ft_file_to_img(t_map *map, void **img, char *path)
{
	int	width;
	int	hight;

	width = 0;
	hight = 0;
	*img = mlx_xpm_file_to_image(map->mlx, path, &width, &hight);
	if (!*img)
	{
		exit_game(map);
		ft_putstr_fd("Error\nmlx_xpm_file_to_image failed\n", 2);
	}
}

//lier les images a la structure img
void	ft_init_img(t_map *map)
{
	ft_file_to_img(map, (void **)&map->img.img_wall, "sprite/wall.xpm");
	ft_file_to_img(map, (void **)&map->img.img_floor, "sprite/floor.xpm");
	ft_file_to_img(map, (void **)&map->img.img_exit, "sprite/exit.xpm");
	ft_file_to_img(map, (void **)&map->img.img_exit_open,
		"sprite/exit_open.xpm");
	ft_file_to_img(map, (void **)&map->img.img_collect, "sprite/collect.xpm");
	ft_file_to_img(map, (void **)&map->img.img_player_up,
		"sprite/player_up.xpm");
	ft_file_to_img(map, (void **)&map->img.img_player_down,
		"sprite/player_down.xpm");
	ft_file_to_img(map, (void **)&map->img.img_player_left,
		"sprite/player_left.xpm");
	ft_file_to_img(map, (void **)&map->img.img_player_right,
		"sprite/player_right.xpm");
	get_enemy_frame(map);
	get_player_frame(map);
	get_screen_frames(map);
}

void	ft_put_wall(t_map *map, unsigned int x, unsigned int y)
{
	if (y == 0 && x == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.screen.frames[0], x * 64, y * 64);
	else if (y == 0 && x == 1)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.screen.frames[1], x * 64, y * 64);
	else if (y == 0 && x == 2)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.screen.frames[2], x * 64, y * 64);
	else
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.img_wall, x * 64, y * 64);
}

void	put_image(t_map *map, void *img, unsigned int x, unsigned int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, x * 64, y * 64);
}

void	ft_put_img(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < map->map_hight)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (map->map[y][x] == '1')
				ft_put_wall(map, x, y);
			else if (map->map[y][x] == '0')
				put_image(map, map->img.img_floor, x, y);
			else if (map->map[y][x] == 'E' && map->count_c != 0)
				put_image(map, map->img.img_exit, x, y);
			else if (map->map[y][x] == 'C')
				put_image(map, map->img.img_collect, x, y);
			else if (map->map[y][x] == 'P' && map->count_steps == 0)
				put_image(map, map->img.pl.frames[map->img.pl.frame], x, y);
			else if (map->map[y][x] == 'N')
				put_image(map, map->img.enm.frames[map->img.enm.frame], x, y);
			x++;
		}
		y++;
	}
}
