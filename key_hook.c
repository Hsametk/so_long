/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:27:39 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/14 18:25:11 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int dest_win()
{
    exit(1);
    return (0);
}

void    move_player(int key, t_state *state)
{
    // printf("%d\n", state->player.x);
    // printf("%d\n", state->player.y);
    ft_printf("%d\n", state->exit.x);

        //ft_printf("%s\n", state->map.board[3]);
    if (key == KEY_D)
    {
        state->map.board[state->player.y][state->player.x] = '0';
        state->map.board[state->player.y][state->player.x + 1] = 'P';
        state->player.x += 1;
    }
    put_screen(state);
}

int handle_key(int key, t_state *state)
{

    if (key == KEY_ESC)
        dest_win();
    else if (key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_W)
         move_player(key, state);
    return (0);
}
