/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:45:56 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/12 11:33:27 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	ft_setmap(t_module *module, char *map)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(map, O_RDONLY);
	module->map->map = ft_calloc(sizeof(char *), ft_maplen(map) + 1);
	while (i < ft_maplen(map))
	{
		module->map->map[i] = get_next_line(fd);
		i++;
	}
	module->map->width = ft_linelen(module->map->map[0]);
	get_next_line(fd);
}
