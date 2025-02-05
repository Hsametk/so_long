/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:52:12 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/05 11:19:21 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
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

    // Harita board'ını yazdırma ve serbest bırakma
    int i = 0;
    while (state.map.board[i] != NULL) {
        ft_printf("%s", state.map.board[i]);
        free(state.map.board[i]); // Eğer `board` malloc ile ayrıldıysa
        i++;
    }
    free(state.map.board); // `board`'u serbest bırak

    // MLX başlatma
    void *mlx_connection = mlx_init();
    if (!mlx_connection) {
        perror("Failed to initialize MLX");
        return EXIT_FAILURE;
    }

    // MLX penceresi oluşturma
    void *mlx_window = mlx_new_window(mlx_connection, 500, 500, "ilk pencerem");
    if (!mlx_window) {
        perror("Failed to create MLX window");
        return EXIT_FAILURE;
    }

    // XPM görüntüsü yükleme
    int x = 500, y = 500;
    void *mlx_new_img = mlx_xpm_file_to_image(mlx_connection, "character.xpm", &x, &y);
    if (!mlx_new_img) {
        perror("Failed to load XPM image");
        return EXIT_FAILURE;
    }

    // Görüntüyü pencereye yerleştirme
    mlx_put_image_to_window(mlx_connection, mlx_window, mlx_new_img, 100, 100);

    // MLX döngüsünü başlatma
    mlx_loop(mlx_connection);

    return 0;
}

/*
to-dos
!!!!!! perror ve exit fonksiyonlarını araştır ilk olarak. !!!!!!
Map kontrolünü yap.
kontroller
-----------
3- map dosyasının uzantısı .ber olmalı. argüman alırken checkle //yazdım ama kontrol et
1- map valid mi yani çevresi 1 lerden oluşuyor mu. //to-do
2- 1 karakter ve 1 çıkış olmalı. en az 1 tane toplanabilir nesne olmalı.
4- oyuncu çıkışa gidebiliyor mu önünde bir engel var mı?
5- map in bilgileri linkled list e atanmalı. Collactable sayısı, exit sayısı, player sayısı.
Map'in boyutu.
6- 

** Kontroller bittikten sonra window açılmalı sonrasında harita ekrana yazdırılmalı.

** Hookları entegre et mouse ve klayve entegresi.

** Duvarlardan geçemeyecek.

** Collactable ın üzerinde gelince sayısını azalt ve resmi floor ile değiştir.

** Çıkışa geldiğinde collactable değişkeninin 0 olması durumunda çık ve window u kapat.

** Çarpıya ve esc ye basılınca window u kapat.

** Haraket sayısını pencereye yazdır.

*/