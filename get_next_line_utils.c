/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:57:55 by stakaki           #+#    #+#             */
/*   Updated: 2021/04/30 00:22:21 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*ft_strdog(char const *s1, char const *s2, char *box);

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

char	*ft_strchr(const char *str, int chr)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == chr && chr == '\0')
		return ((char *)&str[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len_total;
	char	*box;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	i = 0;
	len_total = ft_strlen(s1) + ft_strlen(s2);
	box = (char *)malloc(len_total * sizeof(char) + 1);
	if (box == NULL)
		return (NULL);
	box = ft_strdog(s1, s2, box);
	return (box);
}

char	*ft_strdog(char const *s1, char const *s2, char *box)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		box[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		box[i] = s2[j];
		i++;
		j++;
	}
	box[i] = '\0';
	return (box);
}
