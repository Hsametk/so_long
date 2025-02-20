/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:16:22 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/20 13:48:00 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_recursive(char **tab, t_state *state, int row, int col)
{
	if (!tab || row < 0 || col < 0 || row >= state->map.height
		|| !tab[row] || col >= (int)ft_strlen(tab[row]))
		return ;
	if (tab[row][col] == '1' || tab[row][col] == 'F')
		return ;
	tab[row][col] = 'F';
	fill_recursive(tab, state, row - 1, col);
	fill_recursive(tab, state, row + 1, col);
	fill_recursive(tab, state, row, col - 1);
	fill_recursive(tab, state, row, col + 1);
}

int	check_valid_path(char **map_copy, t_state *state)
{
	int	i;
	int	j;

	i = 0;
	while (state->map.board[i])
	{
		j = 0;
		while (state->map.board[i][j])
		{
			if (state->map.board[i][j] == 'C' || state->map.board[i][j] == 'E')
			{
				if (!map_copy[i] || map_copy[i][j] != 'F')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(char **tab, t_state *state, t_state begin)
{
	if (!tab || !state || !state->map.board)
	{
		ft_printf("Error: Invalid flood fill parameters\n");
		return ;
	}
	if (state->map.height <= 0 || state->map.width <= 0
		|| begin.player.y < 0 || begin.player.x < 0
		|| begin.player.y >= state->map.height
		|| begin.player.x >= state->map.width)
	{
		ft_printf("Error: Invalid flood fill parameters\n");
		return ;
	}
	fill_recursive(tab, state, begin.player.y, begin.player.x);
	if (!check_valid_path(tab, state))
	{
		free_map(tab, state->map.height);
		free_map(state->map.board, state->map.height);
		ft_printf("Error: Invalid map path\n");
		exit(EXIT_FAILURE);
	}
}

char	**copy_map(char **original, int height)
{
	int		i;
	char	**copy;

	copy = calloc(height + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		if (!original[i])
		{
			free_map(copy, i);
			return (NULL);
		}
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			free_map(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
