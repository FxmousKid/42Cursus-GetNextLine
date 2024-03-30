/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:35:04 by inazaria          #+#    #+#             */
/*   Updated: 2024/03/30 20:17:18 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	nl_detection(char *tab)
{
	int	counter;

	counter = 0;
	while (tab && tab[counter])
	{
		if (tab[counter] == '\n')
			return (counter);
		counter++;
	}
	return (-1);
}

size_t	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str && str[index])
		index ++;
	return (index);
}

static char	*ft_memcpy(char *dest, char *s1)
{
	char	*tmp;
	int		counter;

	tmp = dest;
	counter = 0;
	while (s1 && s1[counter])
		*tmp++ = s1[counter++];
	*tmp = 0;
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		size_malloc;
	char	*tmp;

	size_malloc = ft_strlen(s1) + ft_strlen(s2);
	if (size_malloc == 0)
		return (NULL);
	tab = (char *) malloc(sizeof(char) * (size_malloc + 1));
	if (tab == NULL)
		return (NULL);
	tmp = ft_memcpy(ft_memcpy(tab, s1), s2);
	*tmp = 0;
	return (tab);
}

char	**split(char *str, int pos)
{
	char	**output;

	output = malloc(2 * sizeof(char *));
	if (output == NULL)
		return (NULL);
	str[pos] = '\0';
	output[0] = ft_strjoin(str, "\n");
	output[1] = ft_strjoin(str + pos + 1, "");
	free(str);
	return (output);
}
