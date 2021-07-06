/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:19:43 by wokim             #+#    #+#             */
/*   Updated: 2021/04/13 20:53:45 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		is_possible(char *input, int *spot, t_condition *con, int chk_size)
{
	int i;
	int j;
	int start;

	start = spot[0] + (spot[1] * (con->width + 1)) + con->c_len;
	i = chk_size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < chk_size)
		{
			if (input[start + i + j * (con->width + 1)] == con->obs)
				return (-i);
			else if (input[start + i + j * (con->width + 1)] == '\n')
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

int		expand_square(char *input, int *spot, t_condition *con, int chk_size)
{
	int x;
	int y;
	int start_pos;

	if (spot[0] + chk_size > con->width)
		return (0);
	if (spot[1] + chk_size > con->height)
		return (0);
	start_pos = spot[0] + (spot[1] * (con->width + 1)) + con->c_len;
	x = chk_size - 1;
	y = 0;
	while (y < chk_size - 1)
		if (input[start_pos + x + (y * (con->width + 1))] == con->empty)
			y++;
		else
			return (0);
	x = 0;
	while (x < chk_size)
		if (input[start_pos + x + (y * (con->width + 1))] == con->empty)
			x++;
		else
			return (0);
	return (1);
}

int		find_new_max(char *input, t_condition *con, int *spot, int current)
{
	int	i;
	int	flag;

	i = current + 1;
	while (1)
	{
		if (spot[0] + i > con->width || spot[1] + i > con->height)
			return (i - 1);
		flag = is_possible(input, spot, con, i);
		if (flag > 0)
		{
			i++;
			while (expand_square(input, spot, con, i))
				i++;
			return (i - 1);
		}
		else
			return (flag);
	}
}

void	find_max(t_condition *con, char *input, t_pos *pos)
{
	int	max;
	int	spot[2];

	spot[1] = 0;
	while (spot[1] + pos->max < con->height)
	{
		spot[0] = 0;
		while (spot[0] + pos->max < con->width)
		{
			max = find_new_max(input, con, spot, pos->max);
			if (max < 0)
			{
				if (spot[0] - max < con->width)
					spot[0] = spot[0] - max;
			}
			else if (pos->max < max)
			{
				pos->x = spot[0];
				pos->y = spot[1];
				pos->max = max;
			}
			spot[0]++;
		}
		spot[1]++;
	}
}
