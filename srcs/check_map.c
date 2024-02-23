/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:59:14 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 13:09:05 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_count(t_map *map, char c, int i, int j)
{
	if (c == 'P')
	{
		map->pos.x = j;
		map->pos.y = i;
		map->count_p++;
	}
	else if (c == 'E')
	{
		map->count_e++;
		map->exit.x = j;
		map->exit.y = i;
	}
	else if (c == 'C')
		map->count_c++;
	else if (c != '1' && c != '0' && c != 'N')
		return (1);
	return (0);
}

int	check_map_content(t_map *map)
{
	int	i;
	int	j;

	map->count_p = 0;
	map->count_e = 0;
	map->count_c = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (check_count(map, map->map[i][j], i, j))
				return (1);
			j++;
		}
		i++;
	}
	if (map->count_p != 1 || map->count_e != 1 || map->count_c < 1)
		return (1);
	return (0);
}

int	check_map_shape(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != map->map_width)
			return (1);
		i++;
	}
	return (0);
}

int	check_map_wall(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (i == 0 || i == map->map_hight - 1
				|| j == 0 || j == map->map_width - 1)
			{
				if (map->map[i][j] != '1')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	check_map(t_map *map)
{
	if (check_map_content(map))
		return (exit_error("Map invalide", map));
	if (check_map_shape(map))
		return (exit_error("Map invalide", map));
	if (check_map_wall(map))
		return (exit_error("Map invalide", map));
	check_path(map);
}
