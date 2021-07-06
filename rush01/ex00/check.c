/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:17:37 by jhong             #+#    #+#             */
/*   Updated: 2021/04/04 19:28:06 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_check(int *input, int **map)
{
	int i;

	i = -1;
	while (++i < g_size * 4)
	{
		if (i >= g_size * 2)
		{
			if (input[i] != ft_row_count(i % g_size, map, LEFT))
				return (0);
			if (input[i + g_size] != ft_row_count(i % g_size, map, RIGHT))
				return (0);
		}
		else if (i < g_size * 2)
		{
			if (input[i] != ft_col_count(i % g_size, map, UP))
				return (0);
			if (input[i + g_size] != ft_col_count(i % g_size, map, DOWN))
				return (0);
		}
		if ((i + 1) % g_size == 0)
			i += g_size;
	}
	return (1);
}

int		ft_col_count(int col_idx, int **map, int dir)
{
	int cnt;
	int highest;
	int i;

	cnt = 0;
	highest = 0;
	if (dir == UP)
		i = 0;
	else
		i = g_size - 1;
	while (1)
	{
		if (map[i][col_idx] > highest)
		{
			cnt++;
			highest = map[i][col_idx];
			if (highest == g_size)
				return (cnt);
		}
		i += dir;
	}
	return (0);
}

int		ft_row_count(int row_idx, int **map, int dir)
{
	int cnt;
	int highest;
	int i;

	cnt = 0;
	highest = 0;
	if (dir == LEFT)
		i = 0;
	else
		i = g_size - 1;
	while (1)
	{
		if (map[row_idx][i] > highest)
		{
			cnt++;
			highest = map[row_idx][i];
			if (highest == g_size)
				return (cnt);
		}
		i += dir;
	}
	return (0);
}
