/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:15:16 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/12 11:41:43 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

int	ft_checksq(char *map, int len)
{
	int		fd;
	int		i;
	int		first_len;
	int		li;
	char	*line;

	fd = open(map, O_RDONLY);
	i = 1;
	line = get_next_line(fd);
	first_len = ft_linelen(line);
	free(line);
	while (i < len)
	{
		line = get_next_line(fd);
		li = ft_linelen(line);
		if (li != first_len)
		{
			return (free_gnl(line, fd), -1);
		}
		i++;
		free(line);
	}
	return (get_next_line(fd), close(fd), i);
}

int	ft_checkclosefirstline(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_checkclose(char *map, int len)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map, O_RDONLY);
	i = 1;
	line = get_next_line(fd);
	if (ft_checkclosefirstline(line, ft_linelen(line)) < 0)
		return (free_gnl(line, fd), -1);
	free(line);
	while (i < len - 1)
	{
		line = get_next_line(fd);
		if (ft_checkinclose(line, ft_linelen(line)) < 0)
			return (free_gnl(line, fd), -1);
		i++;
		free(line);
	}
	line = get_next_line(fd);
	if (ft_checkclosefirstline(line, ft_linelen(line)) < 0)
		return (get_next_line(fd), free(line), -1);
	return (get_next_line(fd), free(line), close(fd), 1);
}

int	ft_checkforbid(char *map, int len)
{
	int		i;
	char	*line;
	int		fd;
	int		j;

	i = 0;
	j = 0;
	fd = open(map, O_RDONLY);
	while (i < len)
	{
		line = get_next_line(fd);
		while (line[j])
		{
			if (line[j] != '1' && line[j] != '0' && line[j] != 'E'
				&& line[j] != 'P' && line[j] != 'C' && line[j] != '\n')
				return (free_gnl(line, fd), -1);
			j++;
		}
		j = 0;
		i++;
		free(line);
	}
	return (get_next_line(fd), close(fd), 1);
}

int	ft_mapcheck(char *map, int len)
{
	if (ft_checkber(map) == -1 || ft_checksq(map, len) == -1
		|| ft_checkclose(map, len) == -1 || ft_checkforbid(map, len) == -1
		|| has_e(map, len) == -1 || has_p(map, len) == -1
		|| howmuch_c(map, len) == -1)
	{
		printf("Sorry, map is not valid. Try another map.\n");
		return (-1);
	}
	return (1);
}
