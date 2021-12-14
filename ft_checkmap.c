/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:15:16 by ngobert           #+#    #+#             */
/*   Updated: 2021/12/14 16:21:42 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"
#include "get_next_line.h"

int	ft_maplen(char *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map, O_RDONLY);
	while (get_next_line(fd) != NULL)
		i++;
	return (i);
}


