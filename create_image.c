/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:28:08 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/05 15:54:19 by hakotu           ###   ########.fr       */
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
		ft_printf("Failed to upload the image");
}
void	put_screen(t_state *state, int x, int y, int i)
{
    int i;
    int j;
    
    i = 0;
    while (state->map.board[i])
    {
        while (state->map.board[i][j])
        {
            j = 0;
            if (state->map.board[i][j] == '1')
                mlx_put_image_to_window(state->mlx, state->win, state->imgs.w, x , y);
            if (state->map.board[i][j] == 'P')
            {
                mlx_put_image_to_window(state->mlx, state->win, state->imgs.p, x , y); 
                state->player.x = j;
                state->player.y = i;
            }
            put_screen_options(state, &i, &x, &y);
            j++;
        }
        i++;    
    }
}
