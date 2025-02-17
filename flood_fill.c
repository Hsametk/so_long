#include "so_long.h"

void fill(char **tab, int height, int width, int row, int col)
{
    // Out-of-bounds kontrolü
    if (!tab || row < 0 || col < 0 || row >= height || col >= width || !tab[row])
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

void flood_fill(char **tab, t_state *state, t_state begin)
{
    if (!tab || !state || begin.player.y < 0 || begin.player.x < 0 ||
        begin.player.y >= state->map.height || begin.player.x >= state->map.width)
    {
        ft_printf("Error: Invalid flood fill parameters\n");
        return;
    }
    
    fill(tab, state->map.height, state->map.width, begin.player.y, begin.player.x);
}

char **copy_map(char **original, int height)
{
    char **copy = malloc(sizeof(char *) * (height + 1));
    if (!copy)
        return NULL;

    for (int i = 0; i < height; i++)
    {
        copy[i] = ft_strdup(original[i]);
        if (!copy[i])
        {
            free_map(copy, i); // Hata durumunda temizleme
            return NULL;
        }
    }
    copy[height] = NULL;
    return copy;
}

void free_map(char **map, int height)
{
    for (int i = 0; i < height; i++)
        free(map[i]);
    free(map);
}