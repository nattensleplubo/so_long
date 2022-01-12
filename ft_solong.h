/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:26:01 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/12 10:50:25 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLONG_H
# define FT_SOLONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "mlx.h"

# define EMPTY "./assets/sprites/empty.xpm"
# define WALL "./assets/sprites/wall.xpm"
# define COIN "./assets/sprites/collectible.xpm"
# define EXIT "./assets/sprites/exit.xpm"
# define PLAYER "./assets/sprites/player.xpm"

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef enum e_bool {TRUE = 1, FALSE = 0}	t_bool;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_objects
{
	int	p;
	int	c;
	int	e;
}	t_objects;

typedef struct s_map
{
	char	**map; // Done
	char	*file;
	int		fd;
	int		width; // Done
	int		height; // Done
	int		col;
	int		row;
}	t_map;

typedef struct s_player
{
	int	player_x;
	int	player_y;
	int	player_moves;
}	t_player;

typedef struct s_coin
{
	int	coin_total;
	int	coin_taken;
}	t_coin; //DONE

typedef struct s_sprite
{
	void	*wall;
	void	*ground;
	void	*coin;
	void	*exit;
	void	*player;
	int		img_width;
	int		img_height;
}	t_sprite;

typedef struct s_module
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
void	*ft_calloc(size_t count, size_t size);
int		start_game(t_module *module, char *map);
void	ft_setmap(t_module *module, char *map);
int		print_map(t_module *module);
char	*ft_itoa(int n);
void	hook(t_module *module);
size_t	ft_strlenz(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
void	move(t_module *module, int x, int y);
int		close_all(t_module *module);
void	free_ptr(void **ptr);
char	*ft_strjoinz(char const *s1, char const *s2);

#endif
