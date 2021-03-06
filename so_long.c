/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:36:53 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/12 11:29:49 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

int	set_map(t_module *module, char *map)
{
	module->map = malloc(1 * sizeof(t_map));
	module->map->map = NULL;
	if (module->map == NULL)
		return (-1);
	ft_setmap(module, map);
	module->map->height = ft_maplen(map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_module	*module;

	if (argc == 2 && ft_mapcheck(argv[1], ft_maplen(argv[1])) == 1)
	{
		module = malloc(1 * sizeof(t_module));
		if (module == NULL)
			return (-1);
		if (ft_mapcheck(argv[1], ft_maplen(argv[1])) == 1
			&& set_map(module, argv[1]))
		{
			start_game(module, argv[1]);
			hook(module);
			mlx_loop(module->vars->mlx);
		}
	}
}
