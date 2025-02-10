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

void	display_map(struct map *cm)
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
		printf("%i. %i, %i \n", counter + 1, cm->obs[counter][0], cm->obs[counter][1]);
		counter++;
	}
}
