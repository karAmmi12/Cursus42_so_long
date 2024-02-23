/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:50:05 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 15:41:23 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_frame(t_map *map)
{
	ft_file_to_img(map, (void **)&map->img.pl.frames[0],
		"sprite/player_frames/homer1.xpm");
	ft_file_to_img(map, (void **)&map->img.pl.frames[1],
		"sprite/player_frames/homer2.xpm");
}

void	get_enemy_frame(t_map *map)
{
	ft_file_to_img(map, (void **)&map->img.enm.frames[0],
		"sprite/enemy_frames/burn1.xpm");
	ft_file_to_img(map, (void **)&map->img.enm.frames[1],
		"sprite/enemy_frames/burn2.xpm");
	ft_file_to_img(map, (void **)&map->img.enm.frames[2],
		"sprite/enemy_frames/burn3.xpm");
	ft_file_to_img(map, (void **)&map->img.enm.frames[3],
		"sprite/enemy_frames/burn4.xpm");
}

void	get_screen_frames(t_map *map)
{
	ft_file_to_img(map, (void **)&map->img.screen.frames[0],
		"sprite/screen_frames/screen1.xpm");
	ft_file_to_img(map, (void **)&map->img.screen.frames[1],
		"sprite/screen_frames/screen2.xpm");
	ft_file_to_img(map, (void **)&map->img.screen.frames[2],
		"sprite/screen_frames/screen3.xpm");
}

int	update_anim(t_map *map)
{
	static int	frame_count = 0;
	int			x;
	int			y;

	x = map->pos.x;
	y = map->pos.y;
	frame_count++;
	printf("frame_count: %d\n", frame_count);
	if (frame_count % FRAM_DELAY == 0)
	{
		map->img.pl.frame = (map->img.pl.frame + 1) % 2;
		map->img.enm.frame = (map->img.enm.frame + 1) % 4;
		if (!(map->map[y][x] == 'E' || map->map[y][x] == 'N'))
		{
			ft_put_img(map);
			display_steps(map);
		}
	}
	return (0);
}
