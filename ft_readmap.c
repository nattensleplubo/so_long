/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:35:07 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/05 16:19:33 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	set_coin(char *map, t_module *module)
{
	module->coin->coin_total = howmuch_c(map, ft_maplen(map));
	module->coin->coin_taken = 0;
	module->map->height = ft_maplen(map) * 32;
}

void	ft_setmap(t_module *module, char *map)
{
	module->map->fd = open(map, O_RDONLY);
	
}

int	main(void)
{
	t_module *module;

	module = malloc(sizeof(t_module) * 1);
	module->coin = malloc(sizeof(t_coin) * 1);

	set_coin("coucou.ber", module);
	printf("%d %d\n", module->coin->coin_total, module->coin->coin_taken);
}