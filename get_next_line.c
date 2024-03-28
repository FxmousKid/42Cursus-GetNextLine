/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:34:46 by inazaria          #+#    #+#             */
/*   Updated: 2024/03/29 00:29:24 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <threads.h>



char	*get_next_line(int fd)
{
	char			*tmp;
	static char		*current_line;
	char			*buffer_line;
	int				nl_pos;
	char			**eol_split;

	if(nl_detection(current_line) != 1)
		buffer_line = current_line;
	else
		buffer_line = malloc_line(fd);
	while (buffer_line != NULL)
	{
		nl_pos = nl_detection(buffer_line);
		if (nl_pos == -1) {
			tmp = current_line;
			current_line = ft_strjoin(tmp, buffer_line);
			free(tmp);
			if (current_line == NULL)
				return (free(buffer_line), NULL);
			buffer_line = malloc_line(fd);
			continue;
		}
		eol_split = split(buffer_line, nl_pos);
		tmp = ft_strjoin(current_line, eol_split[0]);
		current_line = eol_split[1];
		return (tmp);
	}
	return (NULL);
}

int main(void)
{
	int fd = open("./testfile.txt", O_RDONLY);


	close(fd);
	return (0);
}
