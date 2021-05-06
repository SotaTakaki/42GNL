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
	static char	*next;
	char		*buf;
	ssize_t		return_read;
	char		*next_sentence;

	if (fd < 0 || fd > 256 || BUFFER_SIZE < 0)
		return (-1);
	*line = ft_strdup("");
	buf = ft_strdup(next);
	if (*line == NULL || buf == NULL)
		return (-1);
	//return_read = 1;
	if(next)
	{
		next_sentence = ft_strchr(buf, '\n');
		while(!next_sentence && return_read > 0)
		{
			*line = ft_strjoin(*line, buf);
			if (*line == NULL)
				return (-1);
			free(buf);
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
	if(!next)
	{
		next_sentence = NULL;
		while (!next_sentence && return_read > 0)
		{
			*line = ft_strjoin(*line, buf);
			if (*line == NULL)
				return (-1);
			free(buf);
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
		return (0);
	}
	*next_sentence = '\0';
	*line = ft_strjoin(*line, buf);
	if (*line == NULL)
		return (-1);
	next_sentence++;
	next = ft_strdup(next_sentence);
	if (next = NULL)
		return (-1);
	free(buf);
	return (1);
}