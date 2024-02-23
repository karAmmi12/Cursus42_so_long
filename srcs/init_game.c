/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:31:22 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 13:21:20 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_map *map)
{
	map->mlx_win = NULL;
	map->count_steps = 0;
	map->img.pl.frame = 0;
	map->img.enm.frame = 0;
	map->img.screen.frame = 0;
	mlx_get_screen_size(map->mlx, &map->screen_width, &map->screen_hight);
	if ((int)map->map_width * 64 > map->screen_width
		|| (int)map->map_hight * 64 > map->screen_hight)
	{
		ft_putstr_fd("Error\nMap too big\n", 2);
		exit_game(map);
	}
	map->mlx_win = mlx_new_window(map->mlx, map->map_width * 64,
			map->map_hight * 64, "so_long");
	if (!map->mlx_win)
	{
		ft_putstr_fd("Error\nmlx_new_window failed\n", 2);
		exit_game(map);
	}
	ft_init_img(map);
	ft_put_img(map);
}
