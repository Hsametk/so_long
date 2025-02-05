#include "so_long.h"

// // Recursive function to flood fill an area of a 2D character array
// void fill(char **tab, t_state size, char target, int row, int col)
// {
//     // Check if current row and column values are out of bounds
//     if (row < 0 || col < 0 || row >= size.player.y || col >= size.player.x)
//         return;
    
//     // Check if current cell has already been filled or does not match the target character
//     if (tab[row][col] == 'F' || tab[row][col] != target)
//         return;

//     // Mark current cell as filled
//     tab[row][col] = 'F';

//     // Recursively fill neighboring cells
//     fill(tab, size, target, row -1, col); // fill cell above
//     fill(tab, size, target, row +1, col); // fill cell below
//     fill(tab, size, target, row, col - 1); // fill cell to the left
//     fill(tab, size, target, row, col + 1); // fill cell to the right
// }

// // Function to initiate flood fill from a specified point
// void flood_fill(char **tab, t_state size, t_state begin)
// {
//     char target = tab[begin.player.y][begin.player.x]; // Get the character to fill around
//     fill(tab, size, target, begin.player.y, begin.player.x); // Start the flood fill from the specified point
// }
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
    //ft_printf("Floood başarili.");
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