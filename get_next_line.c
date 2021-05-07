/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:56:09 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/07 13:42:29 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	static char	*next;
	char		*buf;
	char		*tmp;
	ssize_t		return_read;
	int			next_sentence;

	if (fd < 0 || fd > 256 || BUFFER_SIZE < 0)
		return (-1);
	*line = ft_strdup("");
	buf = ft_strdup(next);
	if (*line == NULL || buf == NULL)
		return (-1);
	return_read = 1;
//	printf("buf=%s\n", buf);
	if (next != NULL)
	{
		next_sentence = ft_strchr(buf, '\n');
//		printf("i=%d\n", next_sentence);
		while (next_sentence == -1 && return_read > 0)
		{
			tmp = ft_strdup(*line);
			free(*line);
			*line = NULL;
			*line = ft_strjoin(tmp, buf, -1);
//			printf("line=%s\n", *line);
			if (*line == NULL)
				return (-1);
			buf = (char *)malloc(BUFFER_SIZE + 1);
			if (buf == NULL)
				return (-1);
			return_read = read(fd, buf, BUFFER_SIZE);
			if (return_read == -1)
				return (-1);
			buf[return_read] = '\0';
			next_sentence = ft_strchr(buf, '\n');
//			printf("i=%d\n", next_sentence);
		}
	}
	else
	{
		next_sentence = -1;
		while (next_sentence == -1 && return_read > 0)
		{
			tmp = ft_strdup(*line);
			free(*line);
			*line = NULL;
			*line = ft_strjoin(tmp, buf, -1);
			if (*line == NULL)
				return (-1);
			buf = (char *)malloc(BUFFER_SIZE + 1);
			if (buf == NULL)
				return (-1);
			return_read = read(fd, buf, BUFFER_SIZE);
			if (return_read == -1)
				return (-1);
			buf[return_read] = '\0';
			next_sentence = ft_strchr(buf, '\n');
		}
	}
	if (return_read == 0)
	{
		free(buf);
		buf = NULL;
		free(*line);
		return (0);
	}
//	printf("1:%s\n", buf);
	*line = ft_strjoin(*line, buf, next_sentence);
	if (*line == NULL)
		return (-1);
//	printf("i=%d\n", next_sentence);
//	printf("2:%s\n", buf);
	free(next);
	next = NULL;
	next = ft_strdup(&buf[next_sentence + 1]);
	if (next == NULL)
		return (-1);
//	printf("3:%s\n", buf);
	free(buf);
//	printf("next=%s\n", buf);
	buf = NULL;
	free(*line);
	return (1);
}
