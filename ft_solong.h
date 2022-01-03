/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:26:01 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/02 23:42:55 by ngobert          ###   ########.fr       */
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
