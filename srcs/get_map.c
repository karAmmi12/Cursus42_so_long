/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:36:47 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 12:57:03 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_init_data(t_map *map)
{
	map->data.check = 0;
	map->data.i = 0;
	map->data.check = 0;
	map->data.line = NULL;
	map->data.old_line = NULL;
	map->data.tmp = NULL;
}

static void	process_line(t_map *map)
{
	if (map->data.tmp[0] == '\n')
			map->data.check++;
	if (!map->data.line)
		map->data.line = ft_strdup("");
	map->data.old_line = map->data.line;
	map->data.line = ft_strjoin(map->data.old_line, map->data.tmp);
	free(map->data.old_line);
	free(map->data.tmp);
	map->data.i++;
}

static void	check_errors(t_map *map)
{
	if (map->data.check != 0)
	{
		free(map->data.line);
		exit_read("Error\nMap is not rectangular\n", map);
	}
}

char	**get_map(t_map *map, char *file_name)
{
	ft_init_data(map);
	map->data.fd = open(file_name, O_RDONLY);
	if (map->data.fd < 0)
		exit_read("Error\nCan't open file\n", map);
	while (1)
	{
		map->data.tmp = get_next_line(map->data.fd, 0);
		if (map->data.tmp == NULL)
		{
			if (map->data.i == 0)
				exit_read("Error\nEmpty file\n", map);
			break ;
		}
		process_line(map);
	}
	check_errors(map);
	map->map_hight = map->data.i;
	map->data.map_array = ft_split(map->data.line, '\n');
	free(map->data.line);
	map->map_width = ft_strlen(map->data.map_array[0]);
	close(map->data.fd);
	return (map->data.map_array);
}
