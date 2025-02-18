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

int dest_win(t_state *state)
{
    int i;
    i = 0;
    mlx_destroy_image(state->mlx, state->imgs.c);
    mlx_destroy_image(state->mlx, state->imgs.e);
    mlx_destroy_image(state->mlx, state->imgs.f);
    mlx_destroy_image(state->mlx, state->imgs.p);
    mlx_destroy_image(state->mlx, state->imgs.w);

    mlx_destroy_window(state->mlx, state->win);
    if (state->mlx)
         mlx_destroy_display(state->mlx);
    free(state->mlx);
    while (state->map.board[i])
    {
        free(state->map.board[i]);
        i++;
    }
    free(state->map.board);
    exit(0);
    return (0);
}

int check_next_position(t_state *state, int next_y, int next_x)
{
    char next_pos = state->map.board[next_y][next_x];
    
    if (next_pos == 'C')
    {
        state->collectibles--;
        return (1);
    }
    else if (next_pos == 'E')
    {
        if (state->collectibles == 0)
        {
            state->player.moves++;  // Son hareketi de sayıyoruz
            ft_printf("Moves: %d\n", state->player.moves);  // Son hareket sayısını yazdır
            ft_printf("Game completed! All collectibles collected.\n");
            dest_win(state);
        }
        return (0);  // Exit'e gelince hareket etme
    }
    return (1);
}
void    move_player(int key, t_state *state)
{
    int moved = 0;  // Hareket gerçekleşti mi kontrolü

    if (key == KEY_W)
    {
        if (state->player.y - 1 > 0 && 
            state->map.board[state->player.y - 1][state->player.x] != '1')
        {
            if (check_next_position(state, state->player.y - 1, state->player.x))
            {
                state->map.board[state->player.y][state->player.x] = '0';
                state->map.board[state->player.y - 1][state->player.x] = 'P';
                state->player.y -= 1;
                moved = 1;  // Hareket gerçekleşti
            }
        }
    }
    if (key == KEY_A)
    {
        if (state->player.x - 1 > 0 && 
            state->map.board[state->player.y][state->player.x - 1] != '1')
        {
            if (check_next_position(state, state->player.y, state->player.x - 1))
            {
                state->map.board[state->player.y][state->player.x] = '0';
                state->map.board[state->player.y][state->player.x - 1] = 'P';
                state->player.x -= 1;
                moved = 1;  // Hareket gerçekleşti
            }
        }
    }
    if (key == KEY_S)
    {
        if (state->player.y + 1 < state->map.height && 
            state->map.board[state->player.y + 1][state->player.x] != '1')
        {
            if (check_next_position(state, state->player.y + 1, state->player.x))
            {
                state->map.board[state->player.y][state->player.x] = '0';
                state->map.board[state->player.y + 1][state->player.x] = 'P';
                state->player.y += 1;
                moved = 1;  // Hareket gerçekleşti
            }
        }
    }
    if (key == KEY_D)
    {
        if (state->player.x + 1 < state->map.width && 
            state->map.board[state->player.y][state->player.x + 1] != '1')
        {
            if (check_next_position(state, state->player.y, state->player.x + 1))
            {
                state->map.board[state->player.y][state->player.x] = '0';
                state->map.board[state->player.y][state->player.x + 1] = 'P';
                state->player.x += 1;
                moved = 1;  // Hareket gerçekleşti
            }
        }
    }

    // Sadece hareket gerçekleştiyse sayacı artır
    if (moved)
    {
        state->player.moves++;
        ft_printf("Moves: %d\n", state->player.moves);
    }
    put_screen(state);
}

int handle_key(int key, t_state *state)
{
    // NULL kontrolü ekliyoruz
    if (!state)
        return (0);

    if (key == KEY_ESC)
        dest_win(state);
    else if (key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_W)
        move_player(key, state);
    return (0);
}
