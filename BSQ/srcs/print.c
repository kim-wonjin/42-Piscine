/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:14:02 by wokim             #+#    #+#             */
/*   Updated: 2021/04/13 19:16:08 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_mark(t_pos *pos, char *input, t_condition *con)
{
	int	x;
	int	y;
	int	position;

	y = 0;
	position = con->c_len + pos->x + (pos->y) * (con->width + 1);
	while (y < pos->max)
	{
		x = 0;
		while (x < pos->max)
		{
			input[position + x + y * (con->width + 1)] = con->mark;
			x++;
		}
		y++;
	}
}

void	ft_put_result(char *str, int start)
{
	int		i;

	i = 0;
	while (str[start + i])
		i++;
	write(1, &str[start], i);
}
