/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:35:07 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/03 16:30:11 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	set_coin(char *map, t_module module)
{
	int		fd;
	int		coins;
	int		i;
	char	*line;

	fd = open(map, O_RDONLY);
	
}