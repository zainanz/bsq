/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdetails.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:00:21 by zali              #+#    #+#             */
/*   Updated: 2025/02/10 14:45:23 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	**extract_obstacles(char *file, struct map *m)
{
	int		fd;
	int		**ptr_obs;
	int		ptr_counter;
	int		row;
	int		col;
	char	c;

	row = 1;
	col = 1;
	ptr_counter = 0;
	ptr_obs = malloc(total_obstacles(file, m->icons[1]) * sizeof(int *));
	fd = open(file, O_RDONLY);
	skip_firstline(fd);
	while (read(fd, &c, 1))
	{
		if (c == m->icons[1])
		{
			ptr_obs[ptr_counter] = malloc(2 * sizeof(int));
			ptr_obs[ptr_counter][0] = col;
			ptr_obs[ptr_counter][1] = row;
			ptr_counter++;
		}
		if (col == m->cols)
		{
			row += 1;
			col = 0;
			continue ;
		}
		col++;
	}
	return (ptr_obs);
}

struct map	*ft_mapdetails(char *file)
{
	struct map	*m;
	m = malloc(sizeof(struct map));
	set_icon(file, m);
	m->cols = line_size(file);
	m->obs = extract_obstacles(file, m);
	m->total_obs = total_obstacles(file, m->icons[1]);
	return (m);
}

