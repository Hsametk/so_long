/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:28:08 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/05 13:47:11 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_state *state)
{
	int		img_w;
	int		img_h;
	char	*str;

	str = "srcs/assets/wall.xpm";
	state->imgs.w = mlx_xpm_file_to_image(state->mlx, str, &img_w, &img_h);
	str = "srcs/assets/character.xpm";
	state->imgs.p = mlx_xpm_file_to_image(state->mlx, str, &img_w, &img_h);
	str = "srcs/assets/coin.xpm";
	state->imgs.c = mlx_xpm_file_to_image(state->mlx, str, &img_w, &img_h);
	str = "srcs/assets/exit.xpm";
	state->imgs.e = mlx_xpm_file_to_image(state->mlx, str, &img_w, &img_h);
	if (!state->imgs.w || !state->imgs.p || !state->imgs.c || !state->imgs.e)
		error_message("Failed to upload the image");
}