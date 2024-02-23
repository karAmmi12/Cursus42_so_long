/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:39:47 by kammi             #+#    #+#             */
/*   Updated: 2024/02/22 18:01:11 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_up(t_map *map)
{
	int	next_y;
	int	next_x;

	next_y = map->pos.y - 1;
	next_x = map->pos.x;
	if (!check_wall(map, next_y, next_x))
	{
		if (map->map[next_y][next_x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = '0';
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.img_floor, map->pos.x * 64, map->pos.y * 64);
		map->pos.y -= 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.img_player_up, map->pos.x * 64, map->pos.y * 64);
		map->count_steps++;
		ft_putstr_fd("count steps: ", 1);
		ft_putnbr_fd(map->count_steps, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}

int	move_down(t_map *map)
{
	int	next_y;
	int	next_x;

	next_y = map->pos.y + 1;
	next_x = map->pos.x;
	if (!check_wall(map, next_y, next_x))
	{
		if (map->map[next_y][next_x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = '0';
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.img_floor, map->pos.x * 64, map->pos.y * 64);
		map->pos.y += 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.img_player_down, map->pos.x * 64, map->pos.y * 64);
		map->count_steps++;
		ft_putstr_fd("count steps: ", 1);
		ft_putnbr_fd(map->count_steps, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}

int	move_left(t_map *map)
{
	int	next_y;
	int	next_x;

	next_y = map->pos.y;
	next_x = map->pos.x - 1;
	if (!check_wall(map, next_y, next_x))
	{
		if (map->map[next_y][next_x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = '0';
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.img_floor, map->pos.x * 64, map->pos.y * 64);
		map->pos.x -= 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.img_player_left, map->pos.x * 64, map->pos.y * 64);
		map->count_steps++;
		ft_putstr_fd("count steps: ", 1);
		ft_putnbr_fd(map->count_steps, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}

int	move_right(t_map *map)
{
	int	next_y;
	int	next_x;

	next_y = map->pos.y;
	next_x = map->pos.x + 1;
	if (!check_wall(map, next_y, next_x))
	{
		if (map->map[next_y][next_x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = '0';
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.img_floor, map->pos.x * 64, map->pos.y * 64);
		map->pos.x += 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img.img_player_right, map->pos.x * 64, map->pos.y * 64);
		map->count_steps++;
		ft_putstr_fd("count steps: ", 1);
		ft_putnbr_fd(map->count_steps, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
