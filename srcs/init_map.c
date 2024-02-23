/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:14:57 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 13:17:32 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_map(t_map *map)
{
	int	i;

	i = 0;
	map->img.img_collect = NULL;
	map->img.img_exit = NULL;
	map->img.img_exit_open = NULL;
	map->img.img_floor = NULL;
	map->img.img_wall = NULL;
	map->img.img_player_up = NULL;
	map->img.img_player_down = NULL;
	map->img.img_player_left = NULL;
	map->img.img_player_right = NULL;
	while (i < 4)
	{
		map->img.pl.frames[i] = NULL;
		map->img.enm.frames[i] = NULL;
		map->img.screen.frames[i] = NULL;
		i++;
	}
}
