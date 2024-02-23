/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:57:18 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 12:48:18 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_wall(t_map *map, int y, int x)
{
	if (map->map[y][x] == '1')
		return (1);
	if (map->map[y][x] == 'E' && map->count_c != 0)
		return (1);
	if (map->map[y][x] == 'E' && map->count_c == 0)
	{
		ft_put_img(map);
		mlx_string_put(map->mlx, map->mlx_win, 50, 30, GREEN, "You win");
		mlx_do_sync(map->mlx);
		sleep(3);
		exit_game(map);
	}
	if (map->map[y][x] == 'N')
	{
		ft_put_img(map);
		mlx_string_put(map->mlx, map->mlx_win, 50, 30, RED, "You lose");
		mlx_do_sync(map->mlx);
		sleep(3);
		exit_game(map);
	}
	return (0);
}
