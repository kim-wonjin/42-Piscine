/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:54:44 by jhong             #+#    #+#             */
/*   Updated: 2021/04/04 19:32:06 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

void	ft_print_map(int **map)
{
	int i;
	int j;

	if (map == 0)
		ft_error();
	else
	{
		i = -1;
		while (++i < g_size)
		{
			j = -1;
			while (++j < g_size)
			{
				ft_putchar(map[i][j] + '0');
				if (j < g_size - 1)
					ft_putchar(' ');
			}
			ft_putchar('\n');
		}
	}
}
