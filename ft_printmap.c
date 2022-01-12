/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:27:01 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/12 10:46:00 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	put_img(t_module *module, void *sprite)
{
	mlx_put_image_to_window(module->vars->mlx, module->vars->win, sprite,
		32 * module->map->col, 32 * module->map->row);
}

void	print_coin(t_module *module)
{
	// module->coin->coin_total = module->coin->coin_total + 1;
	put_img(module, module->sprite->coin);
}

void	position_player(t_module *module)
{
	put_img(module, module->sprite->player);
	module->player->player_x = module->map->col;
	module->player->player_y = module->map->row;
}

int	choose_sprite(char *line, t_module *module)
{
	if (line[module->map->col] == '0')
		put_img(module, module->sprite->ground);
	else if (line[module->map->col] == '1')
		put_img(module, module->sprite->wall);
	else if (line[module->map->col] == 'E')
		put_img(module, module->sprite->exit);
	else if (line[module->map->col] == 'C')
		print_coin(module);
	else if (line[module->map->col] == 'P')
		position_player(module);
	else
		return (1);
	return (0);
}

int	print_map(t_module *module)
{
	module->map->row = 0;
	//module->coin->coin_taken = 0;
	while (module->map->row < module->map->height)
	{
		module->map->col = 0;
		while (module->map->col < module->map->width)
		{
			choose_sprite(module->map->map[module->map->row], module);
			module->map->col++;
		}
		module->map->row++;
	}
	return(0);
}