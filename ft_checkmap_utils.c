/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:34:47 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/12 11:36:43 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	free_gnl(char *line, int fd)
{
	while (line != NULL)
		line = (free(line), get_next_line(fd));
	close(fd);
}

int	ft_checkber(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] == 'r' && map[i - 2] == 'e' && map[i - 3] == 'b'
		&& map[i - 4] == '.')
		return (1);
	else
		return (-1);
}

int	ft_maplen(char *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map, O_RDONLY);
	i = 0;
	while (i != -1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (free(line), i);
		i++;
		free(line);
	}
	return (-1);
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	if (str[i - 1] == '\n')
		return (i - 1);
	else
		return (i);
}

int	ft_checkinclose(char *line, int len)
{
	if (line[0] != '1' || line[len - 1] != '1')
		return (-1);
	else
		return (1);
}
