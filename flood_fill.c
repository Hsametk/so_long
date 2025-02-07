#include "so_long.h"

void fill(char **tab, t_state size, char target, int row, int col)
{
    // Out-of-bounds kontrolü
    if (!tab || row < 0 || col < 0 || row >= size.player.y || col >= size.player.x || !tab[row])
        return;

    // Zaten dolu veya hedef karakter değilse durdur
    if (tab[row][col] == 'F' || tab[row][col] != target)
        return;

    // Mevcut hücreyi doldur
    tab[row][col] = 'F';

    // Komşu hücreleri doldur
    fill(tab, size, target, row - 1, col); // Üst hücre
    fill(tab, size, target, row + 1, col); // Alt hücre
    fill(tab, size, target, row, col - 1); // Sol hücre
    fill(tab, size, target, row, col + 1); // Sağ hücre
}

void flood_fill(char **tab, t_state size, t_state begin)
{
    // Başlangıç koordinatları sınır dışıysa durdur
    if (!tab || begin.player.y < 0 || begin.player.x < 0 ||
        begin.player.y >= size.player.y || begin.player.x >= size.player.x || !tab[begin.player.y])
        return;

    char target = tab[begin.player.y][begin.player.x];

    // Eğer hedef karakter dolu hücreyi temsil ediyorsa işlem yapma
    if (target == 'F')
        return;

    // Flood fill başlat
    fill(tab, size, target, begin.player.y, begin.player.x);
    // ft_printf("Floood başarili.");
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