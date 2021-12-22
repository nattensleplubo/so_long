/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:15:16 by ngobert           #+#    #+#             */
/*   Updated: 2021/12/22 10:37:01 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

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

	fd = open(map, O_RDONLY);
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	return (i);
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
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/* ********* Check les P E C ********** */

int	ft_checklinefor(char *map, char c)
{
	int	i;
}

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
		{
			if (line[j] == 'P')
				p++;
			j++;
		}
		j = 0;
		i++;
	}
	if (p != 1)
		return (-1);
	return (1);
} // FAIRE DES FONCTIONS CHECK LINE FOR UN CERTAIN CHAR COMME CA APRES ON PEUT FREE LES LINES DE GNL

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
		{
			if (line[j] == 'E')
				e++;
			j++;
		}
		j = 0;
		i++;
	}
	if (e != 1)
		return (-1);
	return (1);
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
		{
			if (line[j] == 'C')
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	if (c == 0)
		return (-1);
	return (c);
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

int	main(void)
{
	int maplen = ft_maplen("test.ber");
	int fd = open("test.ber", O_RDONLY);
	printf("Map length : %d\n", maplen);
	printf("First line length : %d\n", ft_linelen(get_next_line(fd)));

	printf("Is map square? : %d %d\n", ft_checksq("test.ber", maplen), maplen);
	
	printf("Is map closed? : %d\n", ft_checkclose("test.ber", maplen));

	printf(".ber : %d\n", ft_checkber("test.ber"));
	printf("P : %d\n", has_p("test.ber", maplen));
	printf("E : %d\n", has_e("test.ber", maplen));
	printf("C : %d\n", howmuch_c("test.ber", maplen));
	printf("Is there forbidden char ? : %d\n", ft_checkforbid("test.ber", maplen));

	printf("Is map valid ? : %d\n", ft_mapcheck("test.ber", maplen));
}
