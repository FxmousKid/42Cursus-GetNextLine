/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:40:34 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/23 22:32:26 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_aux(int fd)
{
	static char		*current_line;
	char			**eol_split;
	char			*tmp;
	char			*buffer_line;

	if (ft_strlen_to_char(current_line, '\n') != -1)
		buffer_line = current_line;
	else
		buffer_line = malloc_line(fd);
	current_line = calc_current_line(current_line);
	while (buffer_line != NULL)
	{
		if (ft_strlen_to_char(buffer_line, '\n') == -1)
		{
			current_line = concat_current_line(current_line, buffer_line);
			buffer_line = malloc_line(fd);
			continue ;
		}
		eol_split = split(buffer_line, ft_strlen_to_char(buffer_line, '\n'));
		tmp = concat_current_line(current_line, eol_split[0]);
		return (current_line = eol_split[1], free(eol_split), tmp);
	}
	return (tmp = current_line, current_line = NULL, free(buffer_line), tmp);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	return (get_next_line_aux(fd));
}

char	*calc_current_line(char	*current_line)
{
	if (ft_strlen_to_char(current_line, '\n') != -1)
		return (NULL);
	return (current_line);
}

char	*concat_current_line(char *current_line, char *buffer_line)
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
