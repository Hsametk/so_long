/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:28:08 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/20 13:46:57 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_state *state)
{
	char	*str;
	int		img_w;
	int		img_h;

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

void	write_image(t_state *state, void *img, int x, int y)
{
	mlx_put_image_to_window(state->mlx, state->win, img, x * 32, y * 32);
}

void	put_screen(t_state *state)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (state->map.board[y])
	{
		x = 0;
		while (state->map.board[y][x])
		{
			tile = state->map.board[y][x];
			if (tile == '1')
				write_image(state, state->imgs.w, x, y);
			else if (tile == 'P')
				write_image(state, state->imgs.p, x, y);
			else if (tile == 'C')
				write_image(state, state->imgs.c, x, y);
			else if (tile == 'E')
				write_image(state, state->imgs.e, x, y);
			else if (tile == '0')
				write_image(state, state->imgs.f, x, y);
			x++;
		}
		y++;
	}
}
