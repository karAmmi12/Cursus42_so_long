/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:17:09 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 11:58:27 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_map_copy(t_map *map)
{
	char				**map_copy;
	unsigned int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (map->map_hight + 1));
	if (!map_copy)
		exit_error("Malloc error", map);
	while (i < map->map_hight)
	{
		map_copy[i] = ft_strdup(map->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

// verifier si le chemin est valide
int	map_is_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(char **map, unsigned int x, unsigned int y, t_map *map_s)
{
	if (x >= map_s->map_width || y >= map_s->map_hight || map[y][x] == 'x')
		return ;
	if (map[y][x] == '1' || map[y][x] == 'N')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'x';
		return ;
	}
	map[y][x] = 'x';
	flood_fill(map, x + 1, y, map_s);
	flood_fill(map, x - 1, y, map_s);
	flood_fill(map, x, y + 1, map_s);
	flood_fill(map, x, y - 1, map_s);
}

void	check_path(t_map *map)
{
	char	**map_copy;

	map_copy = NULL;
	map_copy = ft_map_copy(map);
	flood_fill(map_copy, map->pos.x, map->pos.y, map);
	if (map_is_valid(map_copy))
	{
		free_tab(map_copy);
		return ;
	}
	else
	{
		free_tab(map_copy);
		exit_error("Chemin non valide", map);
	}
}
