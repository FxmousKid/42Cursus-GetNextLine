/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:34:46 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/01 17:44:32 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line_aux(int fd)
{
	static char		*current_line[1024];
	char			**eol_split;
	char			*tmp;
	char			*buffer_line;

	if (nl_detection(current_line[fd]) != -1)
		buffer_line = current_line[fd];
	else
		buffer_line = malloc_line(fd);
	current_line[fd] = calc_current_line(current_line[fd]);
	while (buffer_line != NULL && buffer_line[0] != '\0')
	{
		if (nl_detection(buffer_line) == -1)
		{
			current_line[fd] = conc_cur_line(current_line[fd], buffer_line);
			buffer_line = malloc_line(fd);
			continue ;
		}
		eol_split = split(buffer_line, nl_detection(buffer_line));
		tmp = conc_cur_line(current_line[fd], eol_split[0]);
		current_line[fd] = eol_split[1];
		return (free(eol_split), tmp);
	}
	return (free(buffer_line), NULL);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	return (get_next_line_aux(fd));
}

char	*calc_current_line(char	*current_line)
{
	if (nl_detection(current_line) != -1)
		return (0);
	return (current_line);
}

char	*conc_cur_line(char *current_line, char *buffer_line)
{
	char	*tmp;

	tmp = current_line;
	current_line = ft_strjoin(tmp, buffer_line);
	if (current_line == NULL)
	{
		free(tmp);
		free(buffer_line);
		return (NULL);
	}
	free(tmp);
	free(buffer_line);
	return (current_line);
}

char	*malloc_line(int fd)
{
	char	*line;
	int		read_status;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == NULL)
		return (NULL);
	read_status = read(fd, line, BUFFER_SIZE);
	if (read_status < 0)
		return (free(line), NULL);
	line[read_status] = '\0';
	return (line);
}
/*
int main(void)
{
	int fd = open("./testfile.txt", O_RDONLY);
	int fd1 = open("./testfile2.txt", O_RDONLY);

	char *tab = get_next_line(fd);
	char *tab1 = get_next_line(fd1);
	while (tab != NULL)
	{
		printf("%s", tab);
		printf("%s", tab1);
		free(tab);
		free(tab1);
		tab = get_next_line(fd);
		tab1 = get_next_line(fd1);
	}
	free(tab);
	close(fd);
	return (0);
}*/
