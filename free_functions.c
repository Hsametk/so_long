/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:40:52 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/19 18:05:12 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_err(t_state *state)
{
	int	i;

	i = 0;
	while (state->map.board[i])
	{
		free(state->map.board[i]);
		i++;
	}
	free(state->map.board);
}