/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:47:23 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/11 22:26:07 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	clear_map(t_map *map)
{
	while (map->height--)
		free_ptr((void **)&map->map[map->height]);
	free_ptr((void **)&map->map);
	free_ptr((void **)&map);
}

void	close_window(t_module *module)
{
	int	i;

	i = -1;
	mlx_destroy_image(module->vars->mlx, module->sprite->coin);
	mlx_destroy_image(module->vars->mlx, module->sprite->wall);
	mlx_destroy_image(module->vars->mlx, module->sprite->ground);
	mlx_destroy_image(module->vars->mlx, module->sprite->exit);
	mlx_destroy_image(module->vars->mlx, module->sprite->player);
	free_ptr((void **)&module->sprite);
	mlx_destroy_window(module->vars->mlx, module->vars->win);
	mlx_destroy_display(module->vars->mlx);
	free_ptr((void **)&module->vars->mlx);
	free_ptr((void **)&module->vars);
}

int	close_all(t_module *module)
{
	close_window(module);
	clear_map(module->map);
	free_ptr((void **)&module->player);
	free_ptr((void **)&module->coin);
	free_ptr((void **)&module);
	exit(0);
	return (0);
}
