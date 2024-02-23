/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:23:40 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 13:26:43 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_player_frames(t_map *map)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (map->img.pl.frames[i])
			mlx_destroy_image(map->mlx, map->img.pl.frames[i]);
		i++;
	}
}

void	destroy_enemy_frames(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map->img.enm.frames[i])
			mlx_destroy_image(map->mlx, map->img.enm.frames[i]);
		i++;
	}
}

void	destroy_screen_frames(t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (map->img.screen.frames[i])
			mlx_destroy_image(map->mlx, map->img.screen.frames[i]);
		i++;
	}
}

void	destroy_img(t_map *map)
{
	if (map->img.img_exit_open)
		mlx_destroy_image(map->mlx, map->img.img_exit_open);
	if (map->img.img_exit)
		mlx_destroy_image(map->mlx, map->img.img_exit);
	if (map->img.img_collect)
		mlx_destroy_image(map->mlx, map->img.img_collect);
	if (map->img.img_floor)
		mlx_destroy_image(map->mlx, map->img.img_floor);
	if (map->img.img_wall)
		mlx_destroy_image(map->mlx, map->img.img_wall);
	if (map->img.img_player_up)
		mlx_destroy_image(map->mlx, map->img.img_player_up);
	if (map->img.img_player_down)
		mlx_destroy_image(map->mlx, map->img.img_player_down);
	if (map->img.img_player_left)
		mlx_destroy_image(map->mlx, map->img.img_player_left);
	if (map->img.img_player_right)
		mlx_destroy_image(map->mlx, map->img.img_player_right);
}

void	exit_game(t_map *map)
{
	destroy_img(map);
	if (map->img.pl.frames[0])
		destroy_player_frames(map);
	if (map->img.enm.frames[0])
		destroy_enemy_frames(map);
	if (map->img.screen.frames[0])
		destroy_screen_frames(map);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_map(map);
	exit(0);
}
