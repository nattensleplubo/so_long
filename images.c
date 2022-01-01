/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:28:51 by ngobert           #+#    #+#             */
/*   Updated: 2021/12/27 19:00:27 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./assets/coin-1.xpm";
	int		img_width;
	int		img_height;
	void	*mlx_win;
	int		i = 0;
	int		j = 0;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	while (j < 1080)
	{
		while (i < 1920)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, i, j);
			i += 32;
		}
		i = 0;
		j += 32;
	}
	mlx_loop(mlx);
}
