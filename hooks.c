/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:12:33 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/11 22:14:51 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	free_ptr(void **ptr)
{
	if (ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static int	key_hook(int keycode, t_module *module)
{
	if (keycode == 113 || keycode == KEY_ESC)
	 	close_all(module);
	else if (module->end_game == TRUE)
		return (0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move(module, module->player->player_x + 1, module->player->player_y);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move(module, module->player->player_x - 1, module->player->player_y);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move(module, module->player->player_x, module->player->player_y + 1);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move(module, module->player->player_x, module->player->player_y - 1);
	return (0);
}

int	print_steps(t_module *module)
{
	char	*temp;
	char	*itoa;

	itoa = ft_itoa(module->player->player_moves);
	temp = ft_strjoin("STEPS : ", itoa);
	free_ptr((void **)&temp);
	free_ptr((void **)&itoa);
	return (0);
}

void	hook(t_module *module)
{
	mlx_key_hook(module->vars->win, &key_hook, module);
// 	mlx_loop_hook(module->vars->mlx, &print_steps, module);
// 	mlx_hook(module->vars->win, 17, 0, &close_all, module);
// 	mlx_hook(module->vars->win, 9, 1L << 21, &resume_game, module);
}