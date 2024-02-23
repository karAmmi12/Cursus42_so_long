/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:02:32 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 13:27:10 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	cross_close(t_map *map)
{
	exit_game(map);
	return (0);
}

int	esc_close(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
	{
		exit_game(map);
	}
	return (0);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(map);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(map);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_up(map);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(map);
	if (map->count_c == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img_exit_open,
			map->exit.x * 64, map->exit.y * 64);
	return (0);
}

int	display_steps(t_map *map)
{
	char	*str;
	char	*message;

	str = ft_itoa(map->count_steps);
	message = ft_strjoin("Nombre de pas: ", str);
	mlx_string_put(map->mlx, map->mlx_win, 50, 30, WHITE, message);
	free(str);
	free(message);
	return (0);
}
