/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:35:04 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/02 18:48:43 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen_to_char(char *str, char c)
{
	int	index;

	index = 0;
	if (str == NULL)
		return (-1);
	if (c == 0)
	{
		while (str && str[index])
			index++;
		return (index);
	}
	while (str && str[index])
	{
		if (str[index] == c)
			return (index);
		index ++;
	}
	return (-1);
}

char	*malloc_line(int fd)
{
	char	*line;
	int		read_status;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == NULL)
		return (NULL);
	read_status = read(fd, line, BUFFER_SIZE);
	if (read_status <= 0)
		return (free(line), NULL);
	line[read_status] = '\0';
	return (line);
}

static char	*ft_memcpy(char *dest, char *s1)
{
	char	*tmp;
	int		counter;

	tmp = dest;
	counter = 0;
	while (s1 && s1[counter])
		*tmp++ = s1[counter++];
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		size_malloc;
	char	*tmp;

	size_malloc = ft_strlen_to_char(s1, 0) + ft_strlen_to_char(s2, 0);
	if (size_malloc == 0)
		return (NULL);
	tab = (char *) malloc(sizeof(char) * (size_malloc + 1));
	if (tab == NULL)
		return (NULL);
	tmp = ft_memcpy(ft_memcpy(tab, s1), s2);
	*tmp = 0;
	return (tab);
}

char	**split(char *str, int pos)
{
	char	**output;

	output = malloc(2 * sizeof(char *));
	if (output == NULL)
		return (NULL);
	str[pos] = '\0';
	output[0] = ft_strjoin(str, "\n");
	output[1] = ft_strjoin(str + pos + 1, "");
	free(str);
	return (output);
}
