/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:06:48 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/18 18:45:19 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    wall_control(t_state *state)
{
    int     i;

    i = 0;
    while (i < state->map.height)
    {
        if (state->map.board[0][i] != '1' || state->map.board[state->map.height -1][i] != '1')
        {
            errno = EINVAL;
            perror("Incorrect map element.");
            return(free_map_err(state), exit(EXIT_FAILURE));
        }
        i++;
    }
    i = 0;
    while (i < state->map.height)
    {
        if (state->map.board[i][0] != '1' || state->map.board[i][state->map.width - 1] != '1')
        {
            errno = EINVAL; 
            perror("Incorrect map element.");
            return(free_map_err(state), exit(EXIT_FAILURE));
        }
        i++;
    }    
}

void is_space(t_state *state)
{
    int i, j;

    i = 0;
    while (state->map.board[i])
    {
        j = 0;
        while (state->map.board[i][j])
        {
            if (state->map.board[i][j] == ' ')
            {
                // Boşluk çevresindeki hücrelerin kontrolü
                if (i == 0 || j == 0 || state->map.board[i + 1] == NULL || state->map.board[i][j + 1] == '\0' || state->map.board[i - 1][j] == '\0' || 
                    state->map.board[i][j - 1] == '\0' || state->map.board[i - 1][j] == ' ' || state->map.board[i + 1][j] == ' ' ||
                    state->map.board[i][j - 1] == ' ' || state->map.board[i][j + 1] == ' ')
                {
                    errno = EINVAL;
                    perror("Map contains invalid spaces.");
                    exit(EXIT_FAILURE);
                }
            }
            j++;
        }
        i++;
    }
}
void is_missing(t_state *state)
{
    int i;
    int len;
    int first_len;

    i = 0;
    if (!state->map.board[0])
        return ;

    // İlk satırın uzunluğunu al
    first_len = ft_strlen(state->map.board[0]);

    // Tüm satırları kontrol et
    while (state->map.board[i])
    {
        len = ft_strlen(state->map.board[i]);
        
        // Eğer satır uzunluğu ilk satırdan farklıysa, hata ver
        if (len != first_len && state->map.height != i + 1)
        {
            ft_printf("1Error: Map must be rectangular\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }

    // Son satırın uzunluğunu al ve ekstra \0'ı dikkate al
    len = ft_strlen(state->map.board[state->map.height -1]); // index 0 dan başladığı için - 1
    // Eğer son satırın uzunluğu diğer satırlardan farklıysa, hata ver
    if (len+1 != first_len) // \n olmadığğı için
    {
        ft_printf("2Error: Map must be rectangular\n");
        exit(EXIT_FAILURE);
    }
}


void is_any_char(t_state *state)
{
    int i;
    int j;

    i = 0;
    while (state->map.board[i])
    {
        j = 0;
        while (state->map.board[i][j])
        {
            if (state->map.board[i][j] != 'C' && state->map.board[i][j] != 'P' && 
                state->map.board[i][j] != 'E' && state->map.board[i][j] != '0' && 
                state->map.board[i][j] != '1' && state->map.board[i][j] != '\n')
            {
                errno = EINVAL;
                perror("There is a misplaced character on the map.");
                exit(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }   
}

void	cpe_counter(t_state *state)
{
	int	i;
    int j;
	int player;
    int exit;
    
    state->collectibles = 0;
    player = 0;
    exit = 0;
	i = 0;
	while (state->map.board[i])
	{
        j = 0;
        while (state->map.board[i][j])
        {
            if (state->map.board[i][j] == 'P')
                player++;
            if (state->map.board[i][j] == 'E')
                exit++;
            if (state->map.board[i][j]== 'C')
                state->collectibles++;
            j++;
        }
        i++;
	}
	if (player != 1 || exit != 1 || state->collectibles == 0)
		error_message_for_counter("There is a problem with the number of C,P or E");
}
