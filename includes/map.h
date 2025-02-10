/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:02:53 by zali              #+#    #+#             */
/*   Updated: 2025/02/10 17:56:49 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct map
{
	int 	**obs;
	int		total_obs;
	char	*icons;
	int		rows;
	int		cols;
	int		**square;
} map;

int			ft_atoi(char *str);
void		ft_putstr(char *);
struct map	*ft_mapdetails(char *file);
char    	*copy_map(int);
int			**extract_obstacles(char *file, struct map *m);
int     	total_obstacles(char *file, char icon);
int			line_size(char *str);
void		show_obs(int **, int);
void		display_map(struct map *);
void		skip_firstline(int fd);
void		find_square(struct map *);
void		set_icon(char *, struct map *);
void		set_cords(int cords[2][2], struct map *m);
int     	check_row(int, int, int, int, struct map *);
int			check_collision(int x, int y, struct map *m);
void		check_axis(int x, int y, struct map *m);
int			find_sol(int x, int y, struct map *m, int x_off, int updater);
#endif
