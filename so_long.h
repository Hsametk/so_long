/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:01:20 by samcu             #+#    #+#             */
/*   Updated: 2025/02/20 14:07:39 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "srcs/libft/get_next_line/get_next_line.h"
# include "srcs/minilibx-linux/mlx.h"
# include "srcs/libft/libft.h"
# include "srcs/ft_printf/ft_printf.h"

# define KEY_ESC    65307
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_W      119

typedef struct s_map
{
	char	*path;
	int		width;
	int		height;
	char	**board;
	char	*filename;
	int		map_size_width;
	int		map_size_height;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}		t_exit;

typedef struct s_imgs
{
	void	*e;
	void	*p;
	void	*c;
	void	*w;
	void	*f;

}		t_imgs;

typedef struct s_screen
{
	int	screen_width;
	int	screen_height;
}		t_screen;

typedef struct s_state
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_imgs		imgs;
	int			collectibles;
	t_exit		exit;
	t_screen	screen;
}		t_state;

int		initialize_state(char *filename, t_state *state);
void	map_checker(char *map, t_state *my_map);
void	flood_fill(char **tab, t_state *state, t_state begin);
void	read_map(char *map, t_state *my_map);
void	map_error(void);
void	error_filename(void);
char	**copy_map(char **original, int height);
void	free_map(char **map, int height);
void	put_image(t_state *state);
void	put_screen(t_state *state);
void	game_map_locations(t_state *state);
void	map_size(t_state *state);
void	wall_control(t_state *state);
void	cpe_counter(t_state *state);
void	is_missing(t_state *state);
void	is_any_char(t_state *state);
void	error_message_for_counter(char *str);
void	is_space(t_state *state);
int		handle_key(int key, t_state *state);
void	move_player(int key, t_state *state);
int		dest_win(t_state *state);
void	game_map_locations(t_state *state);
int		check_next_position(t_state *state, int next_y, int next_x);
int		check_valid_path(char **map_copy, t_state *state);
void	check_screen_size(t_state *state);
void	free_map_err(t_state *state);

#endif