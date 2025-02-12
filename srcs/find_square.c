/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:47:12 by zali              #+#    #+#             */
/*   Updated: 2025/02/10 19:50:35 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	**decl_cords(int x1, int y1, int x2, int y2)
{
	int	**cords;

	cords = malloc(sizeof(int *) * 2);
	if (!cords)
		return (NULL);
	cords[0] = malloc(sizeof(int) * 2);
	cords[0][0] = x1;
	cords[0][1] = y1;
	cords[1] = malloc(sizeof(int) * 2);
	cords[1][0] = x2;
	cords[1][1] = y2;
	return (cords);
}

int		**find_sol(int x, int y, struct map *m, int x_off)
{
	int	y_size;
	int	**cords;
	int	updater;

	if (x_off == 0)
		return (NULL);
	updater = 1 * (x_off > 0) + -1 * (x_off < 0);
	x_off *= updater;
	y_size = y;
	while ((y - y_size) < x_off && 
		!check_row(x, y_size - 1, updater, x_off, m))
		y_size--;
	printf("Y_SIZE after moving up: %i\n", y_size);
	printf(">> Y: %i\n>> X_OFF, %i\n", y, x_off);
	while ((y - y_size) < x_off &&
		 !check_row(x, y + 1, updater, x_off, m))
		y++;
	if ((y - y_size) != x_off)
		return (0);
	cords = decl_cords(x, y_size, x + (x_off * updater), y);
	printf("Settings cords: (%i, %i), (%i, %i)\n", cords[0][0], cords[0][1], cords[1][0], cords[1][1]);
	//set_cords(cords, m);
	return (cords);
}

void	check_axis(int x, int y, struct map *m, int flipped)
{
	int	x_size;
	int	**cords;
	x_size = x - 1;
	if (flipped)
		ft_swap(&(m->rows), &(m->cols));
	if (x_size > 0)
	{
		while (!check_collision(x_size - 1, y, m))
			x_size--;
		while (!(cords = find_sol(x_size, y, m, (x - 1) - x_size)))
		{
			if ((x - 1 - x_size) == 0)
				break ;
			x_size++;
		}
		set_cords(cords, m, flipped);
	}
	x_size = x + 1;
	if (x_size < m->cols)
	{
		while (!check_collision(x_size + 1, y, m))
			x_size++;
		while (!(cords = find_sol(x_size, y, m, (x + 1) - x_size)))
		{
			if (x + 1 - x_size == 0)
				break ;
			x_size--;
		}
		set_cords(cords, m, flipped);
	}
	if (flipped)
		ft_swap(&(m->rows), &(m->cols));
}

void	find_square(struct map *m)
{
	int	counter;

	counter = 0;
	while (counter < m->total_obs)
	{
		check_axis(m->obs[counter][0], m->obs[counter][1], m, 0);
		check_axis(m->obs[counter][1], m->obs[counter][0], m, 1);
		counter++;
	}
}
