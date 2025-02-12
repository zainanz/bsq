/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:57:05 by zali              #+#    #+#             */
/*   Updated: 2025/02/10 18:02:31 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	main(int argc, char *argv[])
{
	struct map *current_map;
	current_map = ft_mapdetails(argv[1]);
	find_square(current_map);
	display_map(current_map);
	return (argc);
}
