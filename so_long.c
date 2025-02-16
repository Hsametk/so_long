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

Map kontrolünü yap.
kontroller
-----------
1- map valid mi yani çevresi 1 lerden oluşuyor mu. //to-do
2- 1 karakter ve 1 çıkış olmalı. en az 1 tane toplanabilir nesne olmalı.
4- oyuncu çıkışa gidebiliyor mu önünde bir engel var mı?
5- map in bilgileri linkled list e atanmalı. Collactable sayısı, exit sayısı, player sayısı.
Map'in boyutu.
6-


** todo player ın ve ezit in x y sini structa ata

** Hookları entegre et mouse ve klayve entegresi.

** Duvarlardan geçemeyecek.

** Collactable ın üzerinde gelince sayısını azalt ve resmi floor ile değiştir.

** Çıkışa geldiğinde collactable değişkeninin 0 olması durumunda çık ve window u kapat.

** Haraket sayısını shell e yazdır.

** memory leakleri check et˙

** flood fill de null varsa F koyma neye F koyacağını belirt.

** Ekran boyutundan büyük window açma (bunun için mlx in içerisende fonksiyon varmış bak)

** collactable ın üzerine gelince haritanın değerini değiştir fonksiyonu tekrar çağır ve bas.

*/