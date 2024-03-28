/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:35:04 by inazaria          #+#    #+#             */
/*   Updated: 2024/03/28 12:31:40 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line_size(int fd, int line_num)
{
	char	c;
	int		line_size;

	while (line_num > 0)
	{
		read(fd, &c, 1);
		if (c == '\n')
			line_num--;
	}
	line_size = 0;
	while (c != '\0')
	{
		read(fd, &c, 1);
		line_size++;
	}
	return (line_size);
}
