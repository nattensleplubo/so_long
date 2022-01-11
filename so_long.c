/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:36:53 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/11 11:47:33 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

int	main (int argc, char **argv)
{
	t_module	*module;

	if (argc == 2)
	{
		module = malloc(1 * sizeof(t_module));
		if (module == NULL)
			return (-1);
		if (ft_mapcheck(argv[1]) == 1)
	}
}