/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:34:46 by inazaria          #+#    #+#             */
/*   Updated: 2024/03/28 14:07:29 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char		*line;
	static int	line_num;

	line_num = 0;
	line = malloc(sizeof(char) * get_line_size(fd, line_num));
	if (line == NULL)
		return (NULL);
	

	line_num++;
	return (line);
}


int main(void)
{
	int fd = open("./testfile.txt", O_RDONLY);
	printf("line 1 size is %d", get_line_size(fd, 1));
	

	close(fd);
	return (0);
}
