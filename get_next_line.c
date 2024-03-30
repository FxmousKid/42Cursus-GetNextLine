/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:34:46 by inazaria          #+#    #+#             */
/*   Updated: 2024/03/30 20:06:48 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*current_line;
	char			**eol_split;
	char			*tmp;
	char			*buffer_line;

	if (nl_detection(current_line) != -1)
		buffer_line = current_line;
	else
		buffer_line = malloc_line(fd);
	current_line = calc_current_line(current_line);
	while (buffer_line != NULL)
	{
		if (nl_detection(buffer_line) == -1)
		{
			current_line = concat_current_line(current_line, buffer_line);
			buffer_line = malloc_line(fd);
			continue ;
		}
		eol_split = split(buffer_line, nl_detection(buffer_line));
		tmp = concat_current_line(current_line, eol_split[0]);
		current_line = eol_split[1];
		return (free(eol_split), tmp);
	}
	return (free(buffer_line), NULL);
}

char	*calc_current_line(char	*current_line)
{
	if (nl_detection(current_line) != -1)
		return (NULL);
	return (current_line);
}

char	*concat_current_line(char *current_line, char *buffer_line)
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
	if (read_status <= 0)
		return (free(line), NULL);
	line[read_status] = '\0';
	return (line);
}

int main(void)
{
	int fd = open("./testfile.txt", O_RDONLY);
	
	char *tab = get_next_line(fd);
	while (tab != NULL)
	{
		printf("%s", tab);
		free(tab);
		tab = get_next_line(fd);
	}
	free(tab);
	close(fd);
	return (0);
}
