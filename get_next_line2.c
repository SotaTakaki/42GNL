/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:56:09 by stakaki           #+#    #+#             */
/*   Updated: 2021/04/29 23:45:48 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	get_next_line(int fd, char **line)
{
	static char	*leftover;
	char		*buf;
	ssize_t		return_read;
	char		*ready_line;
	char		*place_null;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = strdup("");
	return_read = 1;
	if (leftover == NULL)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (-1);
		buf[BUFFER_SIZE] = '\0';
		return_read = read(fd, buf, BUFFER_SIZE);
		ready_line = strdup(buf);
	}
	else
		ready_line = leftover;
	while (return_read > 0)
	{
		place_null = strchr(ready_line, '\n');
		if(place_null != NULL)
		{
			*place_null = '\0';
			*line = strdup(ready_line);
			place_null++;;
			leftover = strdup(place_null);
			free(buf);
			free(ready_line);
			return (1);
		}
		leftover = strdup(ready_line);
		return_read = read(fd, buf, BUFFER_SIZE);
		free(ready_line);
		ready_line = (char *)malloc(sizeof(char) * (strlen(leftover) + BUFFER_SIZE + 1));
		if (ready_line == NULL)
			return (-1);
		ready_line = strcat(leftover, buf);
	}
	free(buf);
	free(ready_line);
	free(leftover);
	free(line);
	return (0);
}
