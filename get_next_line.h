/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:38:48 by inazaria          #+#    #+#             */
/*   Updated: 2024/04/02 01:55:53 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*calc_current_line(char	*current_line);
char	*concat_current_line(char *current_line, char *buffer_line);
char	*get_next_line(int fd);
char	*malloc_line(int fd);
int		nl_detection(char *tab);
char	*ft_strjoin(char *s1, char *s2);
char	**split(char *str, int pos);
ssize_t	ft_strlen_to_char(char *str, char c);

#endif
