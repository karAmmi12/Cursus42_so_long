/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:48:21 by kammi             #+#    #+#             */
/*   Updated: 2024/02/22 16:23:50 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_putstr_fd("Error\nMalloc failed\n", 2), 1);
	if (ac != 2)
		return (free(map), ft_putstr_fd("Error\nNbr d'args invalide\n", 2), 1);
	if (check_extension(av[1]))
		return (free(map), ft_putstr_fd("Error\nExtension invalide\n", 2), 1);
	ft_init_map(map);
	map->map = get_map(map, av[1]);
	check_map(map);
	map->mlx = mlx_init();
	if (!map->mlx)
		return (free(map), ft_putstr_fd("Error\nmlx_new_window failed\n", 2), 1);
	init_game(map);
	mlx_hook(map->mlx_win, 33, 131072, cross_close, map);
	mlx_hook(map->mlx_win, 2, 1L, esc_close, map);
	mlx_key_hook(map->mlx_win, key_hook, map);
	mlx_loop_hook(map->mlx, update_anim, map);
	mlx_loop(map->mlx);
	free_map(map);
	return (0);
}
