/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:10:06 by hakotu            #+#    #+#             */
/*   Updated: 2025/01/28 14:48:41 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *extract_line(char *line)
{
	size_t	i;
	char	*backup;
	
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[i + 1] = '\0';
	return(backup);
}

static char *read_line(int fd, char *buf, char *backup)
{
    char *temp;
    int read_count;

	read_count = 1;
	while (read_count != '\0')
	{
		read_count = read(fd, buf, BUFFER_SIZE);
		if (read_count == -1)
			return (NULL);
		else if (read_count == 0)
			break ;
		buf[read_count] = '\0';
		if(!backup)
			backup = ft_strdup_two("");
		temp = backup;
		backup = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(backup, '\n'))
			break;
	}
	return (backup);
}

char *get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	char		*line;
	
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = read_line(fd, buf ,backup);
	free(buf);
	buf = NULL;
	if(!line)
		return (NULL);
	backup = extract_line(line);
	return (line);
}
