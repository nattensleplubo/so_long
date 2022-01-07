/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:45:56 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/07 12:56:41 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	set_coin(char *map, t_module *module)
{
	module->coin->coin_total = howmuch_c(map, ft_maplen(map));
	module->coin->coin_taken = 0;
	module->map->height = ft_maplen(map);
}

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

int	main(void)
{
	t_module *module;

	module = malloc(sizeof(t_module) * 1);
	module->coin = malloc(sizeof(t_coin) * 1);
	module->map = malloc(sizeof(t_map));

	set_coin("coucou.ber", module);
	ft_setmap(module, "coucou.ber");
	printf("%d %d\n", module->coin->coin_total, module->coin->coin_taken);
	printf("%d", module->map->width);
}