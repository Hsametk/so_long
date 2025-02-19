/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:16:22 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/19 16:17:36 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill(char **tab, int height, int width, int row, int col)
{
    // Out-of-bounds kontrolü
    if (!tab || row < 0 || col < 0 || row >= height || !tab[row] || col >= (int)ft_strlen(tab[row]))
        return;

    // Duvar veya ziyaret edilmiş hücre kontrolü
    if (tab[row][col] == '1' || tab[row][col] == 'F')
        return;

    // Mevcut hücreyi işaretle
    tab[row][col] = 'F';

    // Tüm yönleri kontrol et
    fill(tab, height, width, row - 1, col);  // yukarı
    fill(tab, height, width, row + 1, col);  // aşağı
    fill(tab, height, width, row, col - 1);  // sol
    fill(tab, height, width, row, col + 1);  // sağ
}

int check_valid_path(char **map_copy, t_state *state)
{
    int i = 0;
    while (state->map.board[i])
    {
        int j = 0;
        while (state->map.board[i][j])
        {
            if (state->map.board[i][j] == 'C' || state->map.board[i][j] == 'E')
            {
                if (!map_copy[i] || map_copy[i][j] != 'F')
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

void flood_fill(char **tab, t_state *state, t_state begin)
{
    if (!tab || !state || !state->map.board || 
        state->map.height <= 0 || state->map.width <= 0 ||
        begin.player.y < 0 || begin.player.x < 0 || 
        begin.player.y >= state->map.height || begin.player.x >= state->map.width)
    {
        ft_printf("Error: Invalid flood fill parameters\n");
        return;
    }
    fill(tab, state->map.height, state->map.width, begin.player.y, begin.player.x);

    // Geçerli yol kontrolü
    if (!check_valid_path(tab, state))
    {
        free_map(tab, state->map.height);
        free_map(state->map.board, state->map.height);

        ft_printf("Error: Invalid map path\n");
        exit(EXIT_FAILURE);
    }
}

char **copy_map(char **original, int height)
{
    char **copy = calloc(height + 1, sizeof(char *));
    if (!copy)
        return NULL;

    int i = 0;
    while (i < height)
    {
        if (!original[i])
        {
            free_map(copy, i); // Hata durumunda temizleme
            return NULL;
        }

        copy[i] = ft_strdup(original[i]);
        if (!copy[i])
        {
            free_map(copy, i); // Hata durumunda temizleme
            return NULL;
        }
        i++;
    }
    copy[height] = NULL;
    return copy;
}

void free_map(char **map, int height)
{
    int i = 0;
    while (i < height)
    {
        free(map[i]);
        i++;
    }
    free(map);
}
