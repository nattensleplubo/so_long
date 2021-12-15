/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:15:16 by ngobert           #+#    #+#             */
/*   Updated: 2021/12/15 16:27:59 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

/* ************************************** Check .ber ************************************ */

int	ft_checkber(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] == 'r' && map[i - 2] == 'e' && map[i - 3] == 'b' && map[i - 4] == '.')
		return (1);
	else
		return (-1);
}

// i - 1 is r

/* ******************************** Map Length ****************************************** */

int	ft_maplen(char *map)
{
	int		fd;
	int		i;

	fd = open(map, O_RDONLY);
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	return (i);
}

/* ************************************ Check Square************************************** */

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

int	ft_checksq(char *map, int len)
{
	int		fd;
	int		i;
	int		first_len;
	int		li;

	fd = open(map, O_RDONLY);
	i = 1;
	first_len = ft_linelen(get_next_line(fd));
	while (i < len)
	{
		li = ft_linelen(get_next_line(fd));
		if (li != first_len)
			return (-1);
		i++;
	}
	return (i);
}

/* ************************************** Check Closed ************************************ */

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

int	ft_checkinclose(char *line, int len)
{
	if (line[0] != '1' || line[len - 1] != '1')
		return (-1);
	else
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
		return (-1);
	free(line);
	while (i < len)
	{
		line = get_next_line(fd);
		
		if (ft_checkinclose(line, ft_linelen(line)) < 0)
			return (-1);
		i++;
	}
	if (ft_checkclosefirstline(line, ft_linelen(line)) < 0)
		return (-1);
	return (1);
}

/* ************************************* Main ************************************* */

int	main(void)
{
	int maplen = ft_maplen("test.ber");
	int fd = open("test.ber", O_RDONLY);
	printf("Map length : %d\n", maplen);
	printf("First line length : %d\n", ft_linelen(get_next_line(fd)));

	printf("Is map square? : %d %d\n", ft_checksq("test.ber", maplen), maplen);
	
	printf("Is map closed? : %d\n", ft_checkclose("test.ber", maplen));

	printf(".ber : %d\n", ft_checkber("test.ber"));
}
