/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:37:55 by jhong             #+#    #+#             */
/*   Updated: 2021/04/04 19:32:04 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_first_process(int *input, int **map, int ***flag)
{
	int idx;

	idx = -1;
	while (++idx < g_size * 4)
	{
		if (input[idx] == g_size)
		{
			if (idx < g_size * 2)
				ft_col_max(idx, map, flag);
			else
				ft_row_max(idx - (g_size * 2), map, flag);
		}
		else if (input[idx] == 1)
			ft_col_row_1(idx, map, flag);
		else
			continue;
	}
}

void	ft_row_max(int idx, int **map, int ***flag)
{
	int value;
	int row;
	int i;

	row = idx % g_size;
	if (idx < g_size)
	{
		value = 0;
		i = row * g_size;
		while (++value <= g_size)
		{
			ft_put_map(i++, map, flag, value);
		}
	}
	else
	{
		value = 0;
		i = (row + 1) * g_size - 1;
		while (++value <= g_size)
		{
			ft_put_map(i--, map, flag, value);
		}
	}
}

void	ft_col_max(int idx, int **map, int ***flag)
{
	int col;
	int value;
	int i;

	col = idx % g_size;
	if (idx < g_size)
	{
		value = 0;
		i = col;
		while (++value <= g_size)
		{
			ft_put_map(i, map, flag, value);
			i += g_size;
		}
	}
	else
	{
		value = 0;
		i = g_size * (g_size - 1) + col;
		while (++value <= g_size)
		{
			ft_put_map(i, map, flag, value);
			i -= g_size;
		}
	}
}

void	ft_col_row_1(int idx, int **map, int ***flag)
{
	int col;
	int row;

	col = 0;
	row = 0;
	if (idx < g_size * 2)
	{
		col = idx % g_size;
		if (idx >= g_size)
			row = g_size - 1;
	}
	else
	{
		row = idx % g_size;
		if (idx >= g_size * 3)
			col = g_size - 1;
	}
	ft_put_map((row * g_size) + col, map, flag, g_size);
}

void	ft_put_map(int idx, int **map, int ***flag, int value)
{
	map[idx / g_size][idx % g_size] = value;
	flag[COL][idx % g_size][value - 1] = TRUE;
	flag[ROW][idx / g_size][value - 1] = TRUE;
}
