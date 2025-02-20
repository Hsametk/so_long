/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:50:43 by samcu             #+#    #+#             */
/*   Updated: 2025/02/20 16:59:04 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
