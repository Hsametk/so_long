/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:30:03 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/21 16:54:16 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file(t_state *map)
{
	size_t	len;

	len = ft_strlen(map->map.filename);
	if (map->map.filename[len - 1] != 'r')
		error_filename();
	if (map->map.filename[len - 2] != 'e')
		error_filename();
	if (map->map.filename[len - 3] != 'b')
		error_filename();
	if (map->map.filename[len - 4] != '.')
		error_filename();
}

void	game_map_locations(t_state *state)
{
	int	i;
	int	j;

	i = -1;
	while (state->map.board[++i])
	{
		j = -1;
		while (state->map.board[i][++j])
		{
			if (state->map.board[i][j] == 'P')
			{
				state->player.y = i;
				state->player.x = j;
			}
			if (state->map.board[i][j] == 'E')
			{
				state->exit.x = i;
				state->exit.y = j;
			}
			if (state->map.board[i][j] == 'C')
				state->collectibles += 1;
		}
	}
}

void	map_size(t_state *state)
{
	int	i;
	int	j;

	if (!state || !state->map.board)
		return ;
	i = 0;
	while (state->map.board[i])
	{
		j = 0;
		while (state->map.board[i][j])
			j++;
		if (j > state->map.width)
			state->map.map_size_width = (j * 32) - 32;
		i++;
	}
	state->map.map_size_height = i * 32;
}

void	check_screen_size(t_state *state)
{
	if (state->map.map_size_width > state->screen.screen_width
		||state->map.map_size_height > state->screen.screen_height)
	{
		free_map_err(state);
		mlx_destroy_display(state->mlx);
		free(state->mlx);
		ft_printf("Error: Map is too big for screen resolution\n");
		exit(EXIT_FAILURE);
	}
}

void	map_checker(char *map, t_state *state)
{
	t_state	begin;
	char	**map_copy;

	check_file(state);
	read_map(map, state);
	map_copy = copy_map(state->map.board, state->map.height);
	if (!map_copy)
	{
		ft_printf("Error: Map copy failed.\n");
		exit(EXIT_FAILURE);
	}
	game_map_locations(state);
	begin.player.x = state->player.x;
	begin.player.y = state->player.y;
	flood_fill(map_copy, state, begin);
	free_map(map_copy, state->map.height);
	wall_control(state);
	is_space(state);
	is_missing(state);
	is_any_char(state);
	cpe_counter(state);
	map_size(state);
}
