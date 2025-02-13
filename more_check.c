/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:06:48 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/13 12:45:15 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void wall_control(t_state *state)
{
    int     i;
    
    i = 0;
    while (i < state->map.width)
    {
        if (state->map.board[0][i] != '1' || state->map.board[state->map.height -1][i] != '1')
        {
            perror("İncorrect map element.");
            return EXIT_FAILURE;
        }
        i++;
    }
    i = 0;
    while (i < state->map.height)
    {
        if (state->map.board[i][0] != '1' || state->map.board[i][state->map.width -1] != '1')
        {
            perror("İncorrect map element.");
            return EXIT_FAILURE;
        }
        i++;   
    }    
}
void is_space(t_state *state)
{
    int i;
    int j;

    i = 0;
    while (state->map.board[i])
    {
        j = 0;
        while (state->map.board[i][j])
        {
            if (state->map.board[i][j] == '\n')
            {
                perror("There is a space on the map.");
                return EXIT_FAILURE;
            }
            j++;
        }
        i++;
    }
}
void	is_missing(t_state *state)
{
	int	i;
	int	a;

	i = 0;
	while (state->map.board[i])
	{
		a = 0;
		while (state->map.board[i][a])
			a++;
		if (a != state->map.height)
        {
			perror("There is a problem with the map");
            return EXIT_FAILURE;
        }
		i++;
    }
}
void is_any_char(t_state *state)
{
    int i;
    int j;
    
    i = 0;
    while (state->map.board[i])
    {
        j = 0;
        while (state->map.board[i][j])
        {
            if (state->map.board[i][j] != 'C' || state->map.board[i][j] != 'P' || state->map.board[i][j] != 'E' ||
                state->map.board[i][j] != '0' || state->map.board[i][j] != '1')
            {
                perror("There is a misplaced character on the map.");
                return EXIT_FAILURE;
            }
            j++;
        }
        i++;
    }   
}
void	cpe_counter(t_state *state)
{
	int	i;
    int j;
	int player;
    int exit;
    
    state->collectibles = 0;
    player = 0;
    exit = 0;
	i = 0;
	while (state->map.board[i])
	{
        while (state->map.board[i][j])
        {
            j = 0;
            if (state->map.board[i][j] == 'P')
                player++;
            if (state->map.board[i][j] == 'E')
                exit++;
            if (state->map.board[i][j]== 'C')
                state->collectibles++;
            i++;
        }
	}
	if (player != 1 || exit != 1 || state->collectibles == 0)
		error_message_for_counter("There is a problem with the number of C,P or E");
}
