/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:12:38 by zali              #+#    #+#             */
/*   Updated: 2025/02/10 13:59:54 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	neg;
	int	total;

	total = 0;
	neg = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		total *= 10;
		total += *str - 48;
		str++;
	}
	if (neg % 2 == 1)
		total *= -1;
	return (total);
}
/*
#include <stdio.h>

int	main()
{
	int	num;
	num = ft_atoi("      -+--2147483648asd");
	printf("%i", num);
}*/
