/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:54:07 by zali              #+#    #+#             */
/*   Updated: 2025/02/10 14:39:16 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_is_square(int row, int col, struct map *cm)
{
	return (row >= ft_min(cm->square[0][0], cm->square[1][0])
		&& row <= ft_max(cm->square[0][0], cm->square[1][0])
		&& col >= ft_min(cm->square[0][1], cm->square[1][1])
		&& col <= ft_max(cm->square[0][1], cm->square[1][1]));
}

int	check_is_obstacle(int row, int col, struct map *cm)
{
	int	counter;

	counter = 0;
	while (counter < cm->total_obs)
	{
		if (cm->obs[counter][0] == col && cm->obs[counter][1] == row)
			return (1);
		counter++;
	}
	return (0);
}

void	display_map(struct map *cm)
{
	int	row;
	int	col;

	row = 1;
	col = 1;
	while (row <= cm->rows)
	{
		col = 1;
		while(col <= cm->cols)
		{
			if (check_is_square(row, col, cm))
				write(1, &cm->icons[0], 1);
			else if (check_is_obstacle(row, col, cm))
				write(1, &cm->icons[1], 1);
			else
				write(1, &cm->icons[2], 1);
			col++;	
		}
		write(1, "\n", 1);
		row++;
	}
}
/*
#include <stdio.h>
void	display_details(struct map *cm)
{	
	int	counter;

	printf("Rows: %i\nCols: %i\n", cm->rows, cm->cols);
	printf("TOTAL SIZE: %i\n", cm->total_obs);
	counter = 0;
	printf("---ICONS--\n");
	while (counter < 3)
	{
		printf("%i.%c\n", counter, cm->icons[counter]);
		counter++;
	}
	counter = 0;
	printf("---CORDS--\n");
	while (counter < cm->total_obs)
	{
		printf("%i. %i, %i \n", 
	counter + 1, cm->obs[counter][0], cm->obs[counter][1]);
		counter++;
	}
	counter = 0;
	printf("First x: %i\n", cm->square[0][0]);
	printf("First y: %i\n", cm->square[0][1]);
	printf("Second x: %i\n", cm->square[1][0]);
	printf("Second y: %i\n", cm->square[1][1]);

}*/
