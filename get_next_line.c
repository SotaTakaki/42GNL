/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:56:09 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/19 21:17:20 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*next;
	ssize_t		return_read;

	if (fd < 0 || fd > 256 || BUFFER_SIZE < 0)
		return (-1);
	*line = ft_strdup("");
	return_read = 1;
	if (*line == NULL)
		return (-1);
	next = ft_repeat_read(line, next, &return_read, fd);
	if (return_read == 0)
	{
		free(next);
		next = NULL;
		return (0);
	}
	if (next == NULL || return_read == -1)
		return (-1);
	return (1);
}

char	*ft_repeat_read(char **line, char *next, ssize_t *return_read, int fd)
{
	int		next_sentence;
	char	*buf;
	char	*tmp;

	next_sentence = ft_strchr(next, '\n');
	buf = ft_strdup(next);
	free(next);
	while (next_sentence == -1 && *return_read > 0)
	{
		*line = ft_strjoin(*line, buf, -1);
		free(buf);
		buf = (char *)malloc(BUFFER_SIZE + 1);
		*return_read = read(fd, buf, BUFFER_SIZE);
		if (*line == NULL || *return_read == -1)
			return (NULL);
		buf[*return_read] = '\0';
		next_sentence = ft_strchr(buf, '\n');
	}
	*line = ft_strjoin(*line, buf, next_sentence);
	tmp = ft_strdup(&buf[next_sentence + 1]);
	if (*line == NULL || tmp == NULL)
		return (NULL);
	free(buf);
	return (tmp);
}
