/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:06:48 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/20 16:58:51 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
