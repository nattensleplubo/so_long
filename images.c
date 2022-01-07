/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:28:51 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/05 21:46:18 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_solong.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./assets/player.xpm";
	int		img_width;
	int		img_height;
	void	*mlx_win;
	int		i = 0;
	int		j = 0;
	int		fd = open(argv[1], O_RDONLY);
	int		length = ft_maplen(argv[1]) * 32;
	int		width = ft_linelen(get_next_line(fd)) * 32;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, length, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	while (j < length)
	{
		while (i < width)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, i, j);
			i += 32;
		}
		i = 0;
		j += 32;
	}
	mlx_loop(mlx);
}

