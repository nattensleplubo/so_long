/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:26:01 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/03 12:48:21 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLONG_H
# define FT_SOLONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# define EMPTY "./assets/sprites/empty.xpm"
# define WALL "./assets/sprites/wall.xpm"
# define COIN "./assets/sprites/coin.xpm"
# define EXIT "./assets/sprites/exit.xpm"
# define PLAYER "./assets/sprites/player.xpm"

typedef enum e_bool {TRUE = 1, FALSE = 0}	t_bool;

typedef	struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct	s_map
{
	char	**map;
	int		fd;
	int		width;
	int		height;
	int		col;
	int		row;
}	t_map;

typedef struct	s_player
{
	int	player_x;
	int	player_y;
	int	player_moves;
}	t_player;

typedef struct	s_coin
{
	int	coin_total;
	int	coin_taken;
}	t_coin;

typedef struct	s_sprite
{
	void	*wall;
	void	*ground;
	void	*coin;
	void	*exit;
	void	*player;
	int		img_width;
	int		img_height;
}	t_sprite;

typedef struct	s_module
{
	t_vars		*vars;
	t_map		*map;
	t_player	*player;
	t_coin		*coin;
	t_sprite	*sprite;
	t_bool		end_game;
}	t_module;

char	*get_next_line(int fd);
int		ft_mapcheck(char *map, int len);
int		howmuch_c(char *map, int len);
int		has_e(char *map, int len);
int		has_p(char *map, int len);
int		ft_checkforbid(char *map, int len);
int		ft_checkclose(char *map, int len);
int		ft_checkinclose(char *line, int len);
int		ft_checkclosefirstline(char *str, int len);
int		ft_checksq(char *map, int len);
int		ft_linelen(char *str);
int		ft_maplen(char *map);
int		ft_checkber(char *map);

#endif
