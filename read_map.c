/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:36:46 by samcu             #+#    #+#             */
/*   Updated: 2025/02/20 13:37:38 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *map)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**allocate_map(int line_count)
{
	char	**arr;

	arr = malloc(sizeof(char *) * (line_count + 1));
	if (!arr)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	return (arr);
}

static void	handle_line_error(char **arr, int j)
{
	perror("Memory allocation failed for line copy");
	free_map(arr, j);
	exit(EXIT_FAILURE);
}

static void	fill_map(char *map, char **arr)
{
	char	*line;
	int		fd;
	int		j;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("Error reopening map file");
		free(arr);
		exit(EXIT_FAILURE);
	}
	j = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		arr[j] = ft_strdup(line);
		if (!arr[j])
			handle_line_error(arr, j);
		free(line);
		j++;
		line = get_next_line(fd);
	}
	arr[j] = NULL;
	close(fd);
}

void	read_map(char *map, t_state *state)
{
	int		line_count;

	state->player.moves = 0;
	line_count = count_lines(map);
	state->map.height = line_count;
	state->map.board = allocate_map(line_count);
	fill_map(map, state->map.board);
	if (line_count > 0)
	{
		state->map.width = ft_strlen(state->map.board[0]);
		if (state->map.board[0][state->map.width - 1] == '\n')
			state->map.width--;
	}
}
