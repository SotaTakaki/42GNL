/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:57:55 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/08 18:34:52 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*box;
	int		i;

	if (src == NULL)
	{
		box = (char *)malloc(sizeof(char) * 1);
		if (box == NULL)
			return (NULL);
		box[0] = '\0';
		return (box);
	}
	box = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (box == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		box[i] = src[i];
		i++;
	}
	box[i] = '\0';
	return (box);
}

int	ft_strchr(const char *str, int chr)
{
	size_t	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return (i);
		i++;
	}
	if (str[i] == chr && chr == '\0')
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2, int i)
{
	int		len_total;
	char	*box;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (i == -1)
		len_total = ft_strlen(s1) + ft_strlen(s2);
	else
		len_total = ft_strlen(s1) + i;
	box = (char *)malloc(len_total * sizeof(char) + 1);
	if (box == NULL)
		return (NULL);
	ft_strdog(s1, s2, box, len_total);
	free(s1);
	s1 = NULL;
	return (box);
}

void	ft_strdog(char *s1, char *s2, char *box, int len_total)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		box[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < len_total)
	{
		box[i] = s2[j];
		i++;
		j++;
	}
	box[i] = '\0';
}
