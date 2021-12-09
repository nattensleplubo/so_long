/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:15:16 by ngobert           #+#    #+#             */
/*   Updated: 2021/12/09 14:43:50 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"


int	ft_checkmapsquare(char *map)
{
	char	*str;
	int		line1;
	int		i;
	int		len;
	int		fd;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	line1 = ft_strlen(str);
	i = 1;
	while (str != NULL)
	{
		str = get_next_line(fd);
		len = ft_strlen(str);
		if (len != line1)
		{
			return (-1);
			close(fd);
		}
		i++;
	}
	close(fd);
	return (i);
}

int	check_ns_borders(char *border)
{
	int	i;

	i = 0;
	while (border[i] != '\n')
	{
		if (border[i] != '1');
			return (-1);
		i++;
	}
}

int	ft_checkmapclosed(char *map, int size)
{
	int		fd;
	char	*line1;
	int		len;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	line1 = get_next_line(fd);
	len = ft_strlen(line1);
	while (str != NULL && i < size)
	{
		if ()
	}
}


// int	ft_checkglobal(char *map)
// {
// 	if (ft_checkmapsquare(map) > 0 && ft_checkmapclosed(map, ft_checkmapsquare) > 0)
// 	{
		
// 	}
// }
