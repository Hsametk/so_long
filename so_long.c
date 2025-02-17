/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:52:12 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/14 13:42:16 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        ft_printf("Usage: ./so_long <map_file>\n");
        return EXIT_FAILURE;
    }
    t_state state;
    state.map.filename = argv[1];
    map_checker(state.map.filename, &state);
    state.mlx = mlx_init();
    if (!state.mlx)
    {
        perror("Failed to initialize MLX");
        return EXIT_FAILURE;
    }
    mlx_get_screen_size(state.mlx, &state.screen.screen_width, &state.screen.screen_height);
    check_screen_size(&state);
    state.win = mlx_new_window(state.mlx, state.map.map_size_width, state.map.map_size_height, "./so_long");
    if (!state.win)
    {
        perror("Failed to create MLX window");
        return EXIT_FAILURE;
    }
    put_image(&state);
    put_screen(&state);
    mlx_key_hook(state.win, &handle_key, &state);
    mlx_hook(state.win, 17, 0, &dest_win, NULL);
    mlx_loop(state.mlx);

    return 0;
}
/*
to-dos

** memory leakleri check et

** Norm kurallarına bak.

*/
