/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:28:08 by wokim             #+#    #+#             */
/*   Updated: 2021/04/10 21:19:58 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				ft_strcpy(char *dst, char *src)
{
	while (*src)
		*(dst++) = *(src++);
	*dst = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *result;
	int			i;

	result = (t_stock_str*)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = (char*)malloc(result[i].size + 1);
		result[i].copy = (char*)malloc(result[i].size + 1);
		ft_strcpy(result[i].str, av[i]);
		ft_strcpy(result[i].copy, av[i]);
		i++;
	}
	result[i].str = 0;
	return (result);
}
