/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:58:07 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/12 13:21:01 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

int	verify_move(t_module *module, char verify)
{
	if (verify == '0')
		return (0);
	if (verify == '1')
		return (1);
	if (verify == 'C')
	{
		module->coin->coin_taken++;
		return (0);
	}
	if (verify == 'E')
	{
		if (module->coin->coin_total == module->coin->coin_taken)
			return (2);
		else
			return (1);
	}
	return (1);
}

void	move(t_module *module, int x, int y)
{
	int	res;

	res = verify_move(module, module->map->map[y][x]);
	//printf("%d out of %d\n", module->coin->coin_taken, module->coin->coin_total);
	if (res == 0)
	{
		module->player->player_moves++;
		module->map->map[y][x] = 'P';
		module->map->map[module->player->player_y]
		[module->player->player_x] = '0';
		print_map(module);
	}
	else if (res == 2)
	{
		printf("\033[32mYOU WIN!\n\033[0");
		module->end_game = TRUE;
	}
}
