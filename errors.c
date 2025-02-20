/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:55:22 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/19 17:56:50 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_filename(void)
{
	ft_printf ("Filename should be a BER extension file");
	exit (EXIT_FAILURE);
}

void	error_message_for_counter(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	exit(EXIT_FAILURE);
}
