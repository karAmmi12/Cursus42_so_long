/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:59:43 by kammi             #+#    #+#             */
/*   Updated: 2024/02/22 17:57:34 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

void	exit_error(char *str, t_map *map)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	free_map(map);
	exit(1);
}

void	exit_read(char *str, t_map *map)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	free(map);
	exit(1);
}
