/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:56:09 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/01 23:02:07 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	static char	*leftover;
	char		*buf;
	ssize_t		return_read;
	char		*place_null;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_strdup("");
	if (*line == NULL)
		return (-1);
	return_read = 1;
	buf = NULL;
	if (leftover == NULL || leftover == ft_strdup(""))
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			free(*line);
			return (-1);
		return_read = read(fd, buf, BUFFER_SIZE);
		buf[return_read] = '\0';
//		printf("%zd\n", return_read);
	}
	else
		buf = leftover;
	place_null = ft_strchr(buf, '\n');
	//printf("%s\n", place_null);
	while (return_read > 0 && place_null == NULL)
	{
	//	printf("%s\n", *line);
		*line = ft_strjoin(*line, buf);
		if (*line == NULL)
			free(buf);
			return (-1);
	//		printf("%s\n", *line);
		return_read = read(fd, buf, BUFFER_SIZE);
		buf[return_read] = '\0';
		place_null = ft_strchr(buf, '\n');
	}
	if (place_null == NULL)
	{
	//	printf("%s\n", *line);
		free(buf);
		return (0);
	}
	*place_null = '\0';
	*line = ft_strjoin(*line, buf);
	if (*line == NULL)
		free(buf);
		return (-1);
	place_null++;
	leftover = place_null;
	free(buf);
	//printf("%d\n", return_read);
	return (1);
}
