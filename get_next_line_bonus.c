/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:34:46 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/22 18:44:00 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line_aux(int fd)
{
	static char		*current_line[2048];
	char			**eol_split;
	char			*tmp;
	char			*buffer_line;

	if (nl_detection(current_line[fd]) != -1)
		buffer_line = current_line[fd];
	else
		buffer_line = malloc_line(fd);
	current_line[fd] = calc_current_line(current_line[fd]);
	while (buffer_line != NULL)
	{
		if (nl_detection(buffer_line) == -1)
		{
			current_line[fd] = conc_cur_line(current_line[fd], buffer_line);
			buffer_line = malloc_line(fd);
			continue ;
		}
		eol_split = split(buffer_line, nl_detection(buffer_line));
		tmp = conc_cur_line(current_line[fd], eol_split[0]);
		return (current_line[fd] = eol_split[1], free(eol_split), tmp);
	}
	tmp = current_line[fd];
	return (current_line[fd] = NULL, free(buffer_line), tmp);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	return (get_next_line_aux(fd));
}

char	*calc_current_line(char	*current_line)
{
	if (nl_detection(current_line) != -1)
		return (NULL);
	return (current_line);
}

char	*conc_cur_line(char *current_line, char *buffer_line)
{
	char	*tmp;

	tmp = current_line;
	if (current_line == NULL)
	{
		current_line = ft_strjoin("", buffer_line);
		free(tmp);
		free(buffer_line);
		return (current_line);
	}
	current_line = ft_strjoin(tmp, buffer_line);
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
	if (read_status <= 0)
		return (free(line), NULL);
	line[read_status] = '\0';
	return (line);
}
