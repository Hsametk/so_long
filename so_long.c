/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:52:12 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/06 12:50:54 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[]) {
    // Argüman sayısı kontrolü
    if (argc != 2) {
        ft_printf("Usage: ./so_long <map_file>\n");
        return EXIT_FAILURE;
    }
    // `my_map.map` doğrudan bir struct olarak kullanılıyor
    t_state state;
    state.map.filename = argv[1]; // Dosya adı alınır
    // Harita kontrolü
    map_checker(state.map.filename, &state);
    // MLX başlatma
    state.mlx = mlx_init();
    if (!state.mlx) {
        perror("Failed to initialize MLX");
        return EXIT_FAILURE;
    }
    // // MLX penceresi oluşturma
    state.map.height = 192;
    state.map.width = 1088;
    state.win = mlx_new_window(state.mlx, state.map.width, state.map.height, "./so_long");
    if (!state.win) {
        perror("Failed to create MLX window");
        return EXIT_FAILURE;
    }
    put_image(&state);
    put_screen(&state);
    // // XPM görüntüsü yükleme
    // int x = 500, y = 500;
    // void *mlx_new_img = mlx_xpm_file_to_image(state.mlx, "character.xpm", &x, &y);
    // if (!mlx_new_img) {
    //     perror("Failed to load XPM image");
    //     return EXIT_FAILURE;
    // }

    // Görüntüyü pencereye yerleştirme
    //mlx_put_image_to_window(state.mlx, state.win, mlx_new_img, 100, 100);

    // MLX döngüsünü başlatma
    mlx_loop(state.mlx);

    return 0;
}


/*
to-dos
!!!!!! perror ve exit fonksiyonlarını araştır ilk olarak. !!!!!!
Map kontrolünü yap.
kontroller
-----------
1- map valid mi yani çevresi 1 lerden oluşuyor mu. //to-do
2- 1 karakter ve 1 çıkış olmalı. en az 1 tane toplanabilir nesne olmalı.
4- oyuncu çıkışa gidebiliyor mu önünde bir engel var mı?
5- map in bilgileri linkled list e atanmalı. Collactable sayısı, exit sayısı, player sayısı.
Map'in boyutu.
6- 

** Windowun boyutunu otomatik hesapla ve struct a ata.

** todo player ın ve ezit in x y sini structa ata

** Hookları entegre et mouse ve klayve entegresi.

** Duvarlardan geçemeyecek.

** Collactable ın üzerinde gelince sayısını azalt ve resmi floor ile değiştir.

** Çıkışa geldiğinde collactable değişkeninin 0 olması durumunda çık ve window u kapat.

** Çarpıya ve esc ye basılınca window u kapat.

** Haraket sayısını pencereye yazdır.

** memory leakleri check et˙
*/