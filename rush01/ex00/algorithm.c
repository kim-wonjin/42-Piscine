/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:22:36 by jhong             #+#    #+#             */
/*   Updated: 2021/04/04 19:31:28 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		**ft_last_process(int idx, int *input, int **map, int ***flag)
{
	int i;
	int **final;

	if (idx == g_size * g_size)
		return (ft_check(input, map) ? map : 0);
	else
	{
		i = -1;
		while (++i < g_size)
		{
			if (map[idx / g_size][idx % g_size] != 0)
				return (ft_last_process(idx + 1, input, map, flag));
			if (flag[COL][idx % g_size][i] || flag[ROW][idx / g_size][i])
				continue;
			ft_put_map(idx, map, flag, i + 1);
			final = ft_last_process(idx + 1, input, map, flag);
			if (final != 0)
				return (final);
			map[idx / g_size][idx % g_size] = 0;
			flag[COL][idx % g_size][i] = FALSE;
			flag[ROW][idx / g_size][i] = FALSE;
		}
	}
	return (0);
}

void	ft_total_process(int *input, int **map, int ***flag)
{
	int i;
	int j;
	int k;

	if (input == 0)
	{
		ft_print_map(0);
		return ;
	}
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < g_size)
		{
			k = -1;
			while (++k < g_size)
			{
				map[j][k] = 0;
				flag[i][j][k] = FALSE;
			}
		}
	}
	ft_first_process(input, map, flag);
	ft_print_map(ft_last_process(0, input, map, flag));
}
