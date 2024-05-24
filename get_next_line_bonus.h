/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:38:48 by inazaria          #+#    #+#             */
/*   Updated: 2024/05/24 16:45:58 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*calc_current_line(char	*current_line);
char	*get_next_line(int fd);
char	*conc_cur_line(char *current_line, char *buffer_line);
char	*malloc_line(int fd);
int		nl_detection(char *tab);
char	*ft_strjoin(char *s1, char *s2);
char	**split(char *str, int pos);

#endif
