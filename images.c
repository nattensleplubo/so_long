/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:28:51 by ngobert           #+#    #+#             */
/*   Updated: 2021/12/20 13:47:43 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./assets/player_1.xpm";
	int		img_width;
	int		img_height;
	void	*mlx_win;
	int		i = 0;
	int		j = 0;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	while (j < 1080)
	{
		while (i < 1920)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, i, j);
			i += 50;
		}
		i = 0;
		j += 50;
	}
	mlx_loop(mlx);
}
