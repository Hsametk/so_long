/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:06:48 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/20 13:50:55 by samcu            ###   ########.fr       */
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

static void	check_rectangular(t_state *state, int first_len)
{
	int	len;

	len = ft_strlen(state->map.board[state->map.height - 1]);
	if (len + 1 != first_len)
	{
		free_map_err(state);
		ft_printf("Error: Map must be rectangular\n");
		exit(EXIT_FAILURE);
	}
	if (state->map.height == first_len)
	{
		free_map_err(state);
		ft_printf("Error: Map must not be square\n");
		exit(EXIT_FAILURE);
	}
}

void	is_missing(t_state *state)
{
	int	i;
	int	len;
	int	first_len;

	i = 0;
	if (!state->map.board[0])
		return ;
	first_len = ft_strlen(state->map.board[0]);
	while (state->map.board[i])
	{
		len = ft_strlen(state->map.board[i]);
		if (len != first_len && state->map.height != i + 1)
		{
			free_map_err(state);
			ft_printf("Error: Map must be rectangular\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	check_rectangular(state, first_len);
}

static void	check_char(t_state *state, char c)
{
	if (c != 'C' && c != 'P' && c != 'E'
		&& c != '0' && c != '1' && c != '\n')
	{
		free_map_err(state);
		errno = EINVAL;
		perror("There is a misplaced character on the map.");
		exit(EXIT_FAILURE);
	}
}

void	is_any_char(t_state *state)
{
	int	i;
	int	j;

	i = -1;
	while (state->map.board[++i])
	{
		j = -1;
		while (state->map.board[i][++j])
		{
			check_char(state, state->map.board[i][j]);
		}
	}
}

static void	count_map_elements(t_state *state, int *p, int *e, int i)
{
	int	j;

	j = -1;
	while (state->map.board[i][++j])
	{
		if (state->map.board[i][j] == 'P')
			(*p)++;
		else if (state->map.board[i][j] == 'E')
			(*e)++;
		else if (state->map.board[i][j] == 'C')
			state->collectibles++;
	}
}

void	cpe_counter(t_state *state)
{
	int	i;
	int	player;
	int	exit;

	state->collectibles = 0;
	player = 0;
	exit = 0;
	i = -1;
	while (state->map.board[++i])
		count_map_elements(state, &player, &exit, i);
	if (player != 1 || exit != 1 || state->collectibles == 0)
	{
		free_map_err(state);
		error_message_for_counter("Invalid number of C,P or E");
	}
}
