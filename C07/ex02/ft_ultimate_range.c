/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:49:32 by wokim             #+#    #+#             */
/*   Updated: 2021/04/12 19:38:26 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *p;
	int val;

	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	p = *range;
	val = min;
	while (val < max)
	{
		*p = val;
		p++;
		val++;
	}
	return (max - min);
}
