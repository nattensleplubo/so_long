/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:56:17 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/07 17:58:08 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	*img_init(char *img, void *mlx, t_sprite *sprite)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image
		(mlx, img, &sprite->img_width, &sprite->img_height);
	return (img_ptr);
}

void	load_sprites(t_vars *vars, t_sprite *sprite)
{
	sprite->wall = img_init(WALL, vars->mlx, sprite);
	sprite->ground = img_init(EMPTY, vars->mlx, sprite);
	sprite->coin = img_init(COIN, vars->mlx, sprite);
	sprite->exit = img_init(EXIT, vars->mlx, sprite);
	sprite->player = img_init(PLAYER, vars->mlx, sprite);	
}

int	start_game(t_module *module)
{
	module->vars = malloc(1 * sizeof(t_vars));
	module->player = malloc(sizeof(t_player));
	module->coin = malloc(sizeof(t_coin));
	module->sprite = malloc(sizeof(t_sprite));
	module->end_game = FALSE;
	if (!module->sprite || !module->vars || !module->player || !module->coin)
		return (-1);
	module->vars->mlx = mlx_init();
	if (module->vars->mlx == NULL)
		return (-1);
	module->vars->win = mlx_new_window(module->vars->mlx,
			module->map->width * 32,
			module->map->height * 32, "so_long");
	if (module->vars->win == NULL)
		return (-1);
	load_sprites(module->vars, module->sprite);
	module->player->player_moves = 0;
}