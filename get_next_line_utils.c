/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:35:04 by inazaria          #+#    #+#             */
/*   Updated: 2024/03/29 00:05:30 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
	
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

int	nl_detection(char *tab)
{
	int	counter;
	
	counter = 0;
	while (tab[counter])
	{
		if (tab[counter] == '\n')
			return (counter);
		counter++;
	}
	return (-1);
}

size_t ft_strlen(char *str) {
	int index;

	index = 0;
	while(str[index])
		index ++;
	return (index);
}

static char	*ft_memcpy(char *dest, char *s1)
{
	char	*tmp;
	int		counter;

	tmp = dest;
	counter = 0;
	while(s1[counter])
		*tmp++ = s1[counter++];
	*tmp = 0;
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		size_malloc;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_malloc = ft_strlen(s1) + ft_strlen(s2);
	tab = (char *) malloc(sizeof(char) * (size_malloc + 1));
	if (tab == NULL)
		return (NULL);
	ft_memcpy(ft_memcpy(tab, s1), s2);
	return (tab);
}

char **split(char *str, int pos) {
	char **output;

	output = malloc(2 * sizeof(char *));
	if (output == NULL)
		return (NULL);
	str[pos] = '\0';
	output[0] = ft_strjoin(str, "\n");
	output[1] = ft_strjoin(str + pos, "");
	return (output);
}

