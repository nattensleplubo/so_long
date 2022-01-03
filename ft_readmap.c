/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:35:07 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/03 18:43:31 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	set_coin(char *map, t_module *module, int len)
{
	int		fd;
	int		j;
	char	*line;
	int		i;

	j = 0;
	i = 0;
	module->coin->coin_total = 0;
	module->coin->coin_taken = 0;
	fd = open(map, O_RDONLY);
	while (i < len)
	{
		line = get_next_line(fd);
		while (line[j])
		{
			if (line[j] == 'C')
				module->coin->coin_total++;
			j++;
		}
		j = (free(line), i++, 0);
	}
	get_next_line(fd);
}

int	main(void)
{
	t_module *module;

	module = malloc(sizeof(t_module) * 1);
	module->coin = malloc(sizeof(t_coin) * 1);

	set_coin("coucou.ber", module, 5);
	printf("%d %d\n", module->coin->coin_total, module->coin->coin_taken);
}