/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:56:09 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/07 17:44:44 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
void	ft_free(char *sentence);
ssize_t	ft_set_line(char **line, char *buf, int *next_sentence, int fd);

int	get_next_line(int fd, char **line)
{
	static char	*next;
	char		*buf;
	ssize_t		return_read;
	int			*next_sentence;

	if (fd < 0 || fd > 256 || BUFFER_SIZE < 0)
		return (-1);
	free(*line);
	*line = NULL;
	//printf("%c\n", 'a');
	buf = ft_strdup(next);
	next_sentence = 1;
//	printf("%c\n", 'a');
	if (buf == NULL)
		return (-1);
	printf("%c\n", 'a');
	return_read = ft_set_line(line, buf, next_sentence, fd);
	if (return_read == -1)
		return (-1);
	if (return_read == 0)
	{
		ft_free(buf);
		ft_free(next);
		return (0);
	}
	*line = ft_strjoin(*line, buf, *next_sentence);
	if (*line == NULL)
		return (-1);
	ft_free(next);
	next = ft_strdup(&buf[*next_sentence + 1]);
	if (next == NULL)
		return (-1);
	ft_free(buf);
	return (1);
}

void	ft_free(char *sentence)
{
	free(sentence);
	sentence = NULL;
}

ssize_t	ft_set_line(char **line, char *buf, int *next_sentence, int fd)
{
	ssize_t	return_read;

	*line = ft_strdup("");
	*next_sentence = ft_strchr(buf, '\n');
	return_read = 1;
	while (*next_sentence == -1 && return_read > 0)
	{
		*line = ft_strjoin(*line, buf, -1);
		if (*line == NULL)
			return (-1);
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (-1);
		return_read = read(fd, buf, BUFFER_SIZE);
		if (return_read == -1)
			return (-1);
		buf[return_read] = '\0';
		*next_sentence = ft_strchr(buf, '\n');
	}
	return (return_read);
}