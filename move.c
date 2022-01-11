/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:58:07 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/11 22:02:15 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	move(t_module *module, int x, int y)
{
	//int	res;

	//res = verify_move(module, module->map->map[y][x]);
	//if (res == 0)
	//{
		module->player->player_moves++;
		module->map->map[y][x] = 'P';
		module->map->map[module->player->player_y][module->player->player_x] = '0';
		print_map(module);
	//}
}