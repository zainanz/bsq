/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:47:12 by zali              #+#    #+#             */
/*   Updated: 2025/02/10 19:00:57 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		find_sol(int x, int y, struct map *m, int x_off, int updater)
{
	int	y_size;
	int	cords[2][2];
	if (x_off == 0)
		return (1);
	cords[0][0] = x_off;
	y_size = y;
	while (!check_collision(x, y_size + 1, m) && !check_row(x, y_size + 1, updater, x_off, m))
		y_size++;
	cords[0][1] = y_size;
	while (y_size < x_off && !check_collision(x, y - 1, m)
		&& !check_row(x, y - 1, updater, x_off, m))
	{
		y--;
		y_size++;
	}
	cords[1][0] = x;
	cords[1][1] = y;
	if (y_size != x_off)
		return (0);
	set_cords(cords, m);
	return (1);
}

void	check_axis(int x, int y, struct map *m)
{
	int	x_size;

	x_size = x;
	while (!check_collision(x_size - 1, y, m))
	{
		x_size--;
	}
	while (!find_sol(x, y, m, x - x_size, 1))
		x_size++;
	write(1, "z-z\n", 1);
	while (!check_collision(x_size + 1, y, m))
		x_size++;
	while (!find_sol(x, y, m, x - x_size, -1))
		x_size--;
}

void	find_square(struct map *m)
{
	int	counter;

	counter = 0;
	while (counter < m->total_obs)
	{
		write(1, "checked obs\n", 12);
		check_axis(m->obs[counter][0], m->obs[counter][1], m);
		//check_axis(m->obs[counter][1], m->obs[counter][0], m);
		counter++;
	}
}
