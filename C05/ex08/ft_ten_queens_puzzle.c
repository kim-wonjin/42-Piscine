/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:03:17 by wokim             #+#    #+#             */
/*   Updated: 2021/04/10 12:48:28 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_result[11];
int		g_y[10];
int		g_z1[19];
int		g_z2[19];
int		g_cnt;

void	set_(int y, int x, int val)
{
	g_y[y] = val;
	g_z1[x - y + 9] = val;
	g_z2[y + x] = val;
}

void	rec(int x)
{
	int y;

	if (x == 10)
	{
		write(1, g_result, 11);
		++g_cnt;
	}
	y = 0;
	while (y < 10)
	{
		if (!g_y[y] && !g_z1[x - y + 9] && !g_z2[y + x])
		{
			set_(y, x, 1);
			g_result[x] = '0' + y;
			rec(x + 1);
			set_(y, x, 0);
		}
		y++;
	}
}

void	init(void)
{
	int i;

	g_result[10] = '\n';
	g_cnt = 0;
	i = 0;
	while (i < 10)
	{
		g_y[i] = 0;
		g_z1[i] = 0;
		g_z2[i] = 0;
		++i;
	}
	while (i < 19)
	{
		g_z1[i] = 0;
		g_z2[i] = 0;
		++i;
	}
}

int		ft_ten_queens_puzzle(void)
{
	init();
	rec(0);
	return (g_cnt);
}
