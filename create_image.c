/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:28:08 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/07 17:12:05 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_image(t_state *state)
{
    int     img_w;
    int     img_h;
    char    *str;

    str = "srcs/assets/wall.xpm";
    state->imgs.w = mlx_xpm_file_to_image(state->mlx, str, &img_w, &img_h);
    str = "srcs/assets/character.xpm";
    state->imgs.p = mlx_xpm_file_to_image(state->mlx, str, &img_w, &img_h);
    str = "srcs/assets/coin.xpm";
    state->imgs.c = mlx_xpm_file_to_image(state->mlx, str, &img_w, &img_h);
    str = "srcs/assets/exit.xpm";
    state->imgs.e = mlx_xpm_file_to_image(state->mlx, str, &img_w, &img_h);
    str = "srcs/assets/floor.xpm";
    state->imgs.f = mlx_xpm_file_to_image(state->mlx, str, &img_w, &img_h);
    if (!state->imgs.w || !state->imgs.p || !state->imgs.c || !state->imgs.e)
        ft_printf("Failed to upload the image");
}
void put_screen(t_state *state)
{
    int     y;
    int     x;

    y = 0;
    while (state->map.board[y])
    {
        x = 0;
        while (state->map.board[y][x])
        {
            if (state->map.board[y][x] == '1')
                mlx_put_image_to_window(state->mlx, state->win, state->imgs.w, x * 32, y * 32);
            if (state->map.board[y][x] == 'P')
                mlx_put_image_to_window(state->mlx, state->win, state->imgs.p, x * 32, y * 32);
            if (state->map.board[y][x] == 'C')
                mlx_put_image_to_window(state->mlx, state->win, state->imgs.c, x * 32, y * 32);
            if (state->map.board[y][x] == 'E')
                mlx_put_image_to_window(state->mlx, state->win, state->imgs.e, x * 32, y * 32);
            if (state->map.board[y][x] == '0')
                mlx_put_image_to_window(state->mlx, state->win, state->imgs.f, x * 32, y * 32);
            x++;
        }
        y++;
    }
}
