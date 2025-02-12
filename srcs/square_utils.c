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
	if (x <= 0 || x > m->cols || y <= 0 || y > m->rows)
	{
		printf("Collided at (%i, %i)", x, y);
		return (1);
	}
	while (counter < m->total_obs)
	{
		if (x == m->obs[counter][0] && y == m->obs[counter][1])
		{
			printf("Collided at (%i, %i)", x, y);
			return (1);
		}
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
int	is_closer(int **cords, struct map *m)
{
	int	cords_width;
	int	m_width;

	cords_width = ABS(cords[0][0] - cords[1][0]);
	m_width = ABS(m->square[0][0] - m->square[1][0]);
	printf("cords:%i\nm_width:%i\n", cords_width, m_width);
	if (cords_width == m_width)
	{
		if (((cords[0][1] - 1) + (cords[1][1] - 1)) < (
					(m->square[0][1] - 1) + (m->square[1][1] - 1)))
			return (0);
		if (((cords[0][0] - 1) + (cords[1][0] - 1)) < (
				(m->square[0][0] - 1) + (m->square[1][0] - 1)))
			return (0);

	}
	return (1);
}
void	set_cords(int **cords, struct map *m, int flipped)
{
	int	square_width;
	
	if (flipped)
	{
		ft_swap(&cords[0][0], &cords[0][1]);	
		ft_swap(&cords[1][0], &cords[1][1]);	
	}
	if (m->square == NULL)
	{
		m->square = malloc(2 * sizeof(int*));
		m->square[0] = malloc(2 * sizeof(int));
		m->square[1] = malloc(2 * sizeof(int));
	}
	square_width = (cords[0][0] - cords[1][0]);
	if (ABS(square_width) < ABS((m->square[0][0] - m->square[1][0])))
	{
		return ;
	}
	if (square_width == ABS(m->square[0][0] - m->square[1][0]))
	{
		if (is_closer(cords, m))
			return ;
	}
	m->square[0][0] = cords[0][0];
	m->square[0][1] = cords[0][1];
	m->square[1][0] = cords[1][0];
	m->square[1][1] = cords[1][1];
}

