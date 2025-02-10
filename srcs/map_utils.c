/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:00:21 by zali              #+#    #+#             */
/*   Updated: 2025/02/10 14:39:24 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		line_size(char *str)
{
	int		fd;
	char 	c;
	int		size;

	size = 0;
	fd = open(str, O_RDONLY);
	if (!fd)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	skip_firstline(fd);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		size++;
	}
	close(fd);
	return (size);
}

void	skip_firstline(int fd)
{
	char	c;

	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
	}
}

int		total_obstacles(char *file, char icon)
{
	int		fd;
	char	c;
	int		total;

	total = 0;
	fd = open(file, O_RDONLY);
	if (!fd){
		write(1, "map error\n", 10);
		return (0);
	}
	skip_firstline(fd);
	while (read(fd, &c, 1))
	{
		if (c == icon)
			total++;
	}
	close(fd);
	return (total);
}

void	set_icon(char *file, struct map *m)
{
	int		fd;
	char	str[100];
	int		str_len;
	char	c;

	str_len = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		str[str_len] = c;
		str_len++;
	}
	close(fd);
	m->icons = malloc(3 * sizeof(char));
	fd = 1;
	while (str_len - 4 < str_len - fd)
	{
		m->icons[fd - 1] = str[str_len - fd];
		str[str_len - fd] = '\0';
		fd++;
	}
	m->rows = ft_atoi(str);
}

