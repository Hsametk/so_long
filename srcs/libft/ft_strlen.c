/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:29:22 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/03 18:02:50 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }
size_t ft_strlen(const char *str) {
    if (str == NULL) {
        return 0; // veya başka uygun bir değer döndür
    }
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
