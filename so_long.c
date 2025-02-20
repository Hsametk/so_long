/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:52:12 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/19 17:17:26 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_state	state;

	if (argc != 2 || !initialize_state(argv[1], &state))
		return (EXIT_FAILURE);
	mlx_get_screen_size(state.mlx, &state.screen.screen_width,
		&state.screen.screen_height);
	check_screen_size(&state);
	state.win = mlx_new_window(state.mlx, state.map.map_size_width,
	state.map.map_size_height, "./so_long");
	if (!state.win)
		return (EXIT_FAILURE);
	put_image(&state);
	put_screen(&state);
	mlx_key_hook(state.win, &handle_key, &state);
	mlx_hook(state.win, 17, 0, &dest_win, &state);
	mlx_loop(state.mlx);
	return (0);
}

int	initialize_state(char *filename, t_state *state)
{
	state->map.filename = filename;
	map_checker(state->map.filename, state);
	state->mlx = mlx_init();
	if (!state->mlx)
	{
		perror("Failed to initialize MLX");
		return (0);
	}
	return (1);
}

/*
to-dos

** Empty ber errors.

** kare map in çalışmamsı lzm.

** memory leakleri check et

** Norm kurallarına bak.

*/
