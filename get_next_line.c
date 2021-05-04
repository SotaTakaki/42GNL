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
char	*ft_lineman(char **line, char *next_sentence, char *sentence);

int	get_next_line(int fd, char **line)
{
	static char	*next;
	char		*buf;
	ssize_t		return_read;
	char		*next_sentence;

	if (fd < 0 || fd > 256)
		return (-1);
	*line = NULL;
	buf = NULL;
	next_sentence = ft_strchr(next, '\n');
	if (next_sentence == NULL)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (-1);
		return_read = read(fd, buf, BUFFER_SIZE);
		buf[return_read] = '\0';
		*line = ft_strdup(next);
		next_sentence = ft_strchr(buf, '\n');
		while (return_read != 0 && next_sentence == NULL)
		{
			*line = ft_strjoin(*line, buf);
			return_read = read(fd, buf, BUFFER_SIZE);
			if (return_read == 0)
				next_sentence = NULL;
			next_sentence = ft_strchr(buf, '\n');
		}
	}
	if (next_sentence != NULL)
	{
		if (buf != NULL)
			next = ft_lineman(line, next_sentence, buf);
		else
			next = ft_lineman(line, next_sentence, next);
		return (1);
	}
	return (0);
}

char	*ft_lineman(char **line, char *next_sentence, char *sentence)
{
	char	*tmp;

	tmp = NULL;
	*next_sentence = '\0';
	tmp = ft_strdup(*line);
	free(*line);
	*line = ft_strjoin(tmp, sentence);
	free(tmp);
	next_sentence++;
	tmp = ft_strdup(next_sentence);
	free(sentence);
	return (tmp);
}