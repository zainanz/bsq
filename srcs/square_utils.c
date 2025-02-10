/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:17:57 by zali              #+#    #+#             */
/*   Updated: 2025/02/10 19:46:11 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		check_collision(int x, int y, struct map *m)
{
	int	counter;

	counter = 0;
	if (x < 0 || x > m->cols)
		return (1);
	if (y < 0 && y > m->rows)
		return (1);
	while (counter < m->total_obs)
	{
		if (x == m->obs[counter][0] && y == m->obs[counter][1])
				return (1);
		counter++;
	}
	return (0);
}

int		check_row(int x, int y, int direction, int size, struct map *m)
{
	int	counter;

	counter = 0;
	while (counter != size)
	{
		x = x + direction;
		if (check_collision(x, y, m))
			return (1);
		counter++;
	}
	return (0);
}

void	set_cords(int cords[2][2], struct map *m)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	if (m->square == NULL)
	{
		m->square = malloc(sizeof(int *) * 2);
		while (i < 2)
		{
			m->square[i] = malloc(sizeof(int) * 2);
			while (j < 2)
			{
				cords[i][j] = cords[i][j];
				j++;
			}
			i++;
		}
	}
	if (cords[0][0] - cords[1][0] > m->square[0][0] - m->square[0][1])
	{
		while (i < 2)
		{
			while (j < 2)
			{
				cords[i][j] = cords[i][j];
				j++;
			}
			i++;
		}
	}
}

