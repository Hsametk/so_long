/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:30:03 by hakotu            #+#    #+#             */
/*   Updated: 2025/01/29 16:23:07 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "fcntl.h"
#include "stdio.h"
//to-do
static void	check_file(t_data *map)
{
	size_t	len;

	len = ft_strlen(map->filename);
	if (map->filename[len - 1] != 'r')
		error_filename();
	if (map->filename[len - 2] != 'e')
		error_filename();
	if (map->filename[len - 3] != 'b')
		error_filename();
	if (map->filename[len - 4] != '.')
		error_filename();
	// if (!ft_strnstr(map->filename, ".ber", ft_strlen(map->filename)))
	// 	error_filename();
}
void read_map(char *map, t_data *my_map)
{
    char    **arr;
    int     fd;
    int     line_count;
    char    *line;
    arr = NULL;
    fd = open(map, O_RDONLY, 777);
    if (fd < 0) {
        perror("Error opening map file");
        exit(EXIT_FAILURE);
    }

    // Dosyanın kaç satır olduğunu öğrenmek için ön okuma
    line_count = 0;
    while ((line = get_next_line(fd)) != NULL) {
        line_count++;
        free(line);
    }
    close(fd);
    my_map->column_len = line_count;    
    // Bellek ayır ve dosyayı yeniden aç
    arr = malloc(sizeof(char *) * (line_count + 1));
    if (!arr) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    fd = open(map, O_RDONLY, 777);
    if (fd < 0) {
        perror("Error reopening map file");
        free(arr);
        exit(EXIT_FAILURE);
    }

    int j = 0;
    while ((line = get_next_line(fd)) != NULL) {
        arr[j] = ft_strdup(line);
        free(line);
        j++;
    }
    my_map->row_len = ft_strlen(line);
    arr[j] = NULL; // Sonlandırıcı ekle
    close(fd);

    my_map->map_details = arr; 
}

//to-do
void    is_map_valid(t_data *my_map)
{
    int i;
    int j;
    t_data map_check;
    i = 0;
    while (map_check.map_details[i] != NULL)
    {
        while (map_check.map_details[i][j] != NULL)
        {
            if (map_check.map_details[0][j] != '1')
            {
                perror("Invalid map!!");
                exit(EXIT_FAILURE);
            }
            if (map_check.map_details[map_check.column_len][j] != '1')
            {
                perror("Invalid map!!!");
                exit(EXIT_FAILURE);
            }
            if (map_check.map_details[i][0] != '1' && map_check.map_details[i][map_check.row_len] != '1')
            {
                perror("Invalid mapp!!!");
                exit(EXIT_FAILURE);
            }
            if (map_check.map_details[i][j] == 'P')
            {
                map_check.
            }
            
        }
    }
}

void map_checker(char *map, t_data *my_map)
{
    check_file(my_map);
    read_map(map, my_map);
    is_map_valid(my_map); //to-do
}
/*
    is_map_valid 

    en üst ve en alt satır 1 lerden oluşmalı
    1 tane karakter ve 1 exit olmalı bunların sayısını tut
    collactable ın sayısını tutmalısın.
    En üst ve en alt haricinde ilk ve son eleman 1 olmalı.
    Tüm satırların uzunluğu aynı olmalı. Ne az ne çok.
    
*/