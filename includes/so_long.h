/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:45:19 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 13:48:35 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

//DEFINES

# define FRAM_DELAY 1500

//STRUCTURES

typedef struct s_player
{
	unsigned int			x;
	unsigned int			y;
}	t_player;

typedef struct s_anim
{
	void		*frames[20];
	int			frame;
}	t_anim;

typedef struct s_data
{
	int		fd;
	int		i;
	int		check;
	char	*line;
	char	*old_line;
	char	**map_array;
	char	*tmp;
}	t_data;

typedef struct s_img
{
	void		*img_floor;
	void		*img_wall;
	void		*img_exit;
	void		*img_collect;
	void		*img_player_up;
	void		*img_player_down;
	void		*img_player_left;
	void		*img_player_right;
	void		*img_exit_open;
	void		*img_enemy;
	t_anim		pl;
	t_anim		enm;
	t_anim		screen;
}	t_img;

typedef struct s_map
{
	unsigned int	map_hight;
	unsigned int	map_width;
	int				count_p;
	int				count_e;
	int				count_c;
	int				count_n;
	int				count_steps;
	int				screen_hight;
	int				screen_width;
	char			**map;
	void			*mlx;
	void			*mlx_win;
	t_data			data;
	t_player		pos;
	t_player		exit;
	t_img			img;
}	t_map;

enum e_keys
{
	KEY_W = 119,
	KEY_UP = 65362,
	KEY_A = 97,
	KEY_LEFT = 65361,
	KEY_S = 115,
	KEY_DOWN = 65364,
	KEY_D = 100,
	KEY_RIGHT = 65363,
	KEY_ESC = 65307,
};

enum e_colors
{
	BLACK = 0x000000,
	WHITE = 0xFFFFFF,
	RED = 0xFF0000,
	GREEN = 0x00FF00,
	BLUE = 0x0000FF,
	YELLOW = 0xFFFF00,
	PURPLE = 0x800080,
	ORANGE = 0xFFA500,
};

//PARSING
int			check_extension(char *str);
char		**get_map(t_map *map, char *file_name);
void		check_map(t_map *map);
int			check_map_content(t_map *map);
int			check_map_shape(t_map *map);
int			check_map_wall(t_map *map);
void		ft_init_map(t_map *map);

//CHECK_PATH
char		**ft_map_copy(t_map *map);
void		flood_fill(char **map, unsigned int x, unsigned int y,
				t_map *map_struct);
void		check_path(t_map *map);
int			map_is_valid(char **map);

//EXIT
void		free_map(t_map *map);
void		free_tab(char **tab);
void		exit_error(char *str, t_map *map);
void		exit_read(char *str, t_map *map);
void		exit_game(t_map *map);
void		destroy_player_frames(t_map *map);
void		destroy_enemy_frames(t_map *map);
void		destroy_screen_frames(t_map *map);

//INIT_GAME
void		init_game(t_map *map);
int			cross_close(t_map *map);
int			esc_close(int keycode, t_map *map);

//PUT_IMG
void		ft_init_img(t_map *map);
void		ft_put_img(t_map *map);
void		ft_file_to_img(t_map *map, void **img, char *path);
void		ft_put_wall(t_map *map, unsigned int x, unsigned int y);
void		put_image(t_map *map, void *img, unsigned int x, unsigned int y);

//DISPLAY
int			display_steps(t_map *map);
int			update_anim(t_map *map);
void		get_player_frame(t_map *map);
void		get_enemy_frame(t_map *map);
void		get_screen_frames(t_map *map);

//MOVE
int			key_hook(int keycode, t_map *map);
int			move_up(t_map *map);
int			move_down(t_map *map);
int			move_left(t_map *map);
int			move_right(t_map *map);
int			check_wall(t_map *map, int x, int y);

#endif
