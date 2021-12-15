/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:15:16 by ngobert           #+#    #+#             */
/*   Updated: 2021/12/14 17:29:00 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

int	ft_maplen(char *map)
{
	int		fd;
	int		i;

	fd = open(map, O_RDONLY);
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}

/* ************************************************************************** */

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
	close(fd);
	return (i);
}

/* ************************************************************************** */

int	main(void)
{
	int maplen = ft_maplen("test.ber");
	int fd = open("test.ber", O_RDONLY);
	printf("Map length : %d\n", maplen);
	printf("First line length : %d\n", ft_linelen(get_next_line(fd)));
	// close(fd);

	printf("Is map square? : %d %d\n", ft_checksq("test.ber", maplen), maplen);
}
