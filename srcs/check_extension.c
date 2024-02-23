/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:35:51 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 11:51:53 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_extension(char *str)
{
	if (str[0] == '.')
		return (1);
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '.')
	{
		str++;
		if (ft_strlen(str) == 3 && str[0] == 'b' && str[1] == 'e'
			&& str[2] == 'r')
			return (0);
	}
	return (1);
}
