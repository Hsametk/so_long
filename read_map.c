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

void	read_map(char *map, t_state *state)
{
	char	**arr;
	char	*line;
	int		fd;
	int		line_count;

	state->player.moves = 0;
	arr = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}
	line_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		free(line);
	}
	state->map.height = line_count;
	close(fd);
	arr = malloc(sizeof(char *) * (line_count + 1));
	if (!arr)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	fd = open(map, O_RDONLY);
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
		if (arr[j] == NULL)
		{
			perror("Memory allocation failed for line copy");
			exit(EXIT_FAILURE);
		}
		free(line);
		j++;
	}
	arr[j] = NULL;
	close(fd);
	state->map.board = arr;
	if (line_count > 0)
	{
		state->map.width = ft_strlen(arr[0]);
		if (arr[0][state->map.width - 1] == '\n')
			state->map.width--;
	}
}