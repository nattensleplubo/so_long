/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:12:33 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/11 16:37:44 by ngobert          ###   ########.fr       */
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
	//mlx_key_hook(module->vars->win, &key_hook, module);
	mlx_loop_hook(module->vars->mlx, &print_steps, module);
}