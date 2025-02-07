/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:30:03 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/07 17:15:58 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "fcntl.h"
// to-do
static void check_file(t_state *map)
{
	size_t len;

	len = ft_strlen(map->map.filename);
	if (map->map.filename[len - 1] != 'r')
		error_filename();
	if (map->map.filename[len - 2] != 'e')
		error_filename();
	if (map->map.filename[len - 3] != 'b')
		error_filename();
	if (map->map.filename[len - 4] != '.')
		error_filename();
	// if (!ft_strnstr(map->filename, ".ber", ft_strlen(map->filename)))
	// 	error_filename();
}
void read_map(char *map, t_state *my_map)
{
	char **arr;
	int fd;
	int line_count;
	char *line;
	arr = NULL;
	fd = open(map, O_RDONLY, 777);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}

	// Dosyanın kaç satır olduğunu öğrenmek için ön okuma
	line_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		free(line);
	}
	close(fd);
	my_map->map.height = line_count;
	// Bellek ayır ve dosyayı yeniden aç
	arr = malloc(sizeof(char *) * (line_count + 1));
	if (!arr)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	fd = open(map, O_RDONLY, 777);
	if (fd < 0)
	{
		perror("Error reopening map file");
		free(arr);
		exit(EXIT_FAILURE);
	}

	int j = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		arr[j] = ft_strdup(line);
		free(line);
		j++;
	}
	my_map->map.width = ft_strlen(line);
	arr[j] = NULL; // Sonlandırıcı ekle
	close(fd);

	my_map->map.board = arr;
}

void map_checker(char *map, t_state *state)
{
	char **map_copy = copy_map(state->map.board, state->map.height);
	if (!map_copy)
	{
		ft_printf("Error: Map copy failed.\n");
		exit(EXIT_FAILURE);
	}

	t_state begin;
	begin.player.x = state->player.x;
	begin.player.y = state->player.y;

	check_file(state);
	read_map(map, state);
	flood_fill(map_copy, *state, begin);
	// is_map_valid(state); //to-do
	map_size(state);
	// free_map(map_copy, state->map.height);
}
// void is_map_valid(t_state *state)
// {
//     int i;
//     int j;

//     i = 0;
//     while (state->map.board[i])
//     {
//         while (state->map.board[i][j])
//         {
//             if (state->map.board[i][j] == 'P')
//             {
//                 state->player.x = i;
//                 state->player.y = j;
//             }

//         }

//     }

//}

void game_map_locations(t_state *state)
{
	int i;
	int j;
	i = 0;
	while (state->map.board[i])
	{
		j = 0;
		while (state->map.board[i][j])
		{
			if (state->map.board[i][j] == 'P')
			{
				state->player.x = i;
				state->player.y = j;
			}
			if (state->map.board[i][j] == 'E')
			{
				state->exit.x = i;
				state->exit.y = j;
			}
			if (state->map.board[i][j] == 'C')
			{
				state->collectibles += 1;
			}
			j++;
		}
		i++;
	}
}
// void map_size(t_state *state)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     state->map.height = 0;
//     state->map.width = 0;
//     while (state->map.board[i])
//         i++;
//     state->map.height = i * 32;
//     while (state->map.board[i][j])
//         j++;
//     state->map.width = j * 32;
// }

void map_size(t_state *state)
{
	int i;
	int j;

	if (!state || !state->map.board)
		return;

	i = 0;
	state->map.height = 0;
	state->map.width = 0;
	while (state->map.board[i])
	{
		j = 0;
		while (state->map.board[i][j])
			j++;
		if (j > state->map.width)
			state->map.width = (j * 32) - 32;
		i++;
	}
	state->map.height = i * 32;
}

/*
	is_map_valid

	en üst ve en alt satır 1 lerden oluşmalı
	1 tane karakter ve 1 exit olmalı bunların sayısını tut
	collactable ın sayısını tutmalısın.
	En üst ve en alt haricinde ilk ve son eleman 1 olmalı.
	Tüm satırların uzunluğu aynı olmalı. Ne az ne çok.

*/