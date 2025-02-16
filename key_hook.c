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
    // Sınır kontrolü ve duvar kontrolü ekliyoruz
    if (key == KEY_D)
    {
        // Sağa hareket etmeden önce kontrol
        if (state->player.x + 1 < state->map.width && 
            state->map.board[state->player.y][state->player.x + 1] != '1')
        {
            state->map.board[state->player.y][state->player.x] = '0';
            state->map.board[state->player.y][state->player.x + 1] = 'P';
            state->player.x += 1;
        }
    }
    if (key == KEY_A)
    {
        // Sağa hareket etmeden önce kontrol
        if (state->player.x - 1 > 0 && 
            state->map.board[state->player.y][state->player.x - 1] != '1')
        {
            state->map.board[state->player.y][state->player.x] = '0';
            state->map.board[state->player.y][state->player.x - 1] = 'P';
            state->player.x -= 1;
        }
    }
    if (key == KEY_S)
    {
        // Sağa hareket etmeden önce kontrol
        if (state->player.y + 1 < state->map.height && 
            state->map.board[state->player.y + 1][state->player.x] != '1')
        {
            state->map.board[state->player.y][state->player.x] = '0';
            state->map.board[state->player.y + 1][state->player.x] = 'P';
            state->player.y += 1;
        }
    }
    if (key == KEY_W)
    {
        // Yukarı hareket etmeden önce kontrol
        if (state->player.y - 1 > 0 && 
            state->map.board[state->player.y - 1][state->player.x] != '1')
        {
            state->map.board[state->player.y][state->player.x] = '0';
            state->map.board[state->player.y - 1][state->player.x] = 'P';
            state->player.y -= 1;
        }
    }
    // Diğer yönler için de benzer kontroller eklenebilir
    put_screen(state);
}

int handle_key(int key, t_state *state)
{
    // NULL kontrolü ekliyoruz
    if (!state)
        return (0);

    if (key == KEY_ESC)
        dest_win();
    else if (key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_W)
        move_player(key, state);
    return (0);
}
