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
//	return_read = 1;
	buf = NULL;
	if (leftover == NULL || leftover == ft_strdup(""))
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (-1);
		return_read = read(fd, buf, BUFFER_SIZE);
		buf[return_read] = '\0';
//		printf("%zd\n", return_read);
	}
	else
		buf = leftover;
	place_null = ft_strchr(buf, '\n');
	while (return_read > 0 && place_null == NULL)
	{
		*line = ft_strjoin(*line, buf);
		if (*line == NULL)
			return (-1);
		return_read = read(fd, buf, BUFFER_SIZE);
		place_null = ft_strchr(buf, '\n');
	}
	*place_null = '\0';
	*line = ft_strjoin(*line, buf);
	if (*line == NULL)
		return (-1);
	place_null++;
	leftover = place_null;
	if (return_read == 0)
	{
		free(buf);
		free(leftover);
		free(*line);
		*line = ft_strdup("");
		return (0);
	}
	return (1);
}
