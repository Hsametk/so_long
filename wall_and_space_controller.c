/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_and_space_controller.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:48:27 by samcu             #+#    #+#             */
/*   Updated: 2025/02/20 16:59:24 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_horizontal_walls(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->map.width)
	{
		if (state->map.board[0][i] != '1'
			|| state->map.board[state->map.height - 1][i] != '1')
		{
			errno = EINVAL;
			perror("Incorrect map element.");
			free_map_err(state);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	check_vertical_walls(t_state *state)
{
	int	i;

	i = -1;
	while (++i < state->map.height)
	{
		if (state->map.board[i][0] != '1'
			|| state->map.board[i][state->map.width - 1] != '1')
		{
			errno = EINVAL;
			perror("Incorrect map element.");
			free_map_err(state);
			exit(EXIT_FAILURE);
		}
	}
}

void	wall_control(t_state *state)
{
	check_horizontal_walls(state);
	check_vertical_walls(state);
}

static void	check_space_conditions(t_state *state, int i, int j)
{
	if (i == 0 || j == 0 || state->map.board[i + 1] == NULL
		|| state->map.board[i][j + 1] == '\0'
		|| state->map.board[i - 1][j] == '\0'
		|| state->map.board[i][j - 1] == '\0'
		|| state->map.board[i - 1][j] == ' '
		|| state->map.board[i + 1][j] == ' '
		|| state->map.board[i][j - 1] == ' '
		|| state->map.board[i][j + 1] == ' ')
	{
		free_map_err(state);
		errno = EINVAL;
		perror("Map contains invalid spaces.");
		exit(EXIT_FAILURE);
	}
}

void	is_space(t_state *state)
{
	int	i;
	int	j;

	i = 0;
	while (state->map.board[i])
	{
		j = 0;
		while (state->map.board[i][j])
		{
			if (state->map.board[i][j] == ' ')
				check_space_conditions(state, i, j);
			j++;
		}
		i++;
	}
}
