/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap_more_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:40:11 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/12 11:46:35 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

int	has_p(char *map, int len)
{
	int		i;
	int		fd;
	char	*line;
	int		p;
	int		j;

	i = 0;
	j = 0;
	p = 0;
	fd = open(map, O_RDONLY);
	while (i < len)
	{
		line = get_next_line(fd);
		while (line[j])
			p += (line[j++] == 'P');
		j = (free(line), i++, 0);
	}
	return (get_next_line(fd), close(fd), 1 - 2 * (p != 1));
}

int	has_e(char *map, int len)
{
	int		i;
	int		fd;
	char	*line;
	int		e;
	int		j;

	i = 0;
	j = 0;
	e = 0;
	fd = open(map, O_RDONLY);
	while (i < len)
	{
		line = get_next_line(fd);
		while (line[j])
			e += (line[j++] == 'E');
		j = (free(line), i++, 0);
	}
	return (get_next_line(fd), close(fd), 1 - 2 * (e != 1));
}

int	howmuch_c(char *map, int len)
{
	int		i;
	int		fd;
	char	*line;
	int		c;
	int		j;

	i = 0;
	j = 0;
	c = 0;
	fd = open(map, O_RDONLY);
	while (i < len)
	{
		line = get_next_line(fd);
		while (line[j])
			c += (line[j++] == 'C');
		j = (free(line), i++, 0);
	}
	if (c == 0)
		return (get_next_line(fd), -1);
	return (get_next_line(fd), close(fd), c);
}
