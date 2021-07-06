/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:22:46 by jhong             #+#    #+#             */
/*   Updated: 2021/04/04 19:32:56 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		malloc_for_map(int ***map)
{
	int i;
	int **map_size;

	map_size = (int**)malloc(sizeof(int*) * g_size);
	if (map_size == NULL)
		return (0);
	i = -1;
	while (++i < g_size)
	{
		map_size[i] = (int*)malloc(sizeof(int) * g_size);
		if (map_size[i] == NULL)
			return (0);
	}
	*map = map_size;
	return (1);
}

int		malloc_for_flag(int ****flag)
{
	int i;
	int j;
	int ***flag_size;

	flag_size = (int***)malloc(sizeof(int**) * 2);
	if (flag_size == NULL)
		return (0);
	i = -1;
	while (++i < 2)
	{
		flag_size[i] = (int**)malloc(sizeof(int*) * g_size);
		if (flag_size[i] == NULL)
			return (0);
		j = -1;
		while (++j < g_size)
		{
			flag_size[i][j] = (int*)malloc(sizeof(int) * g_size);
			if (flag_size[i][j] == NULL)
				return (0);
		}
	}
	*flag = flag_size;
	return (1);
}

void	malloc_for_free(int *input, int **map, int ***flag)
{
	int i;
	int j;

	i = -1;
	free(input);
	while (++i < 2)
	{
		j = -1;
		while (++j < g_size)
		{
			if (i == 0)
				free(map[j]);
			free(flag[i][j]);
		}
		free(flag[i]);
	}
	free(map);
	free(flag);
}

int		main(int argc, char *argv[])
{
	int *input;
	int **map;
	int ***flag;

	if (argc != 2 && ft_error())
		return (0);
	input = ft_split(argv[1], " ");
	if (input == 0 && ft_error())
		return (0);
	g_size = ft_get_size(ft_count(input));
	if ((!malloc_for_map(&map) || !malloc_for_flag(&flag)) && ft_error())
		return (0);
	ft_total_process(input, map, flag);
	malloc_for_free(input, map, flag);
	return (0);
}
