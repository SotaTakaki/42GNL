/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:57:03 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/08 18:32:36 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_repeat_read(char **line, char *next, ssize_t *return_read, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *src);
int		ft_strchr(const char *str, int chr);
char	*ft_strjoin(char *s1, char *s2, int i);
void	ft_strdog(char *s1, char *s2, char *box, int len_total);

#endif
