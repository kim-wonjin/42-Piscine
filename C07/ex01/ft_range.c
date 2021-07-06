/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:25:35 by wokim             #+#    #+#             */
/*   Updated: 2021/04/12 17:39:30 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *result;
	int i;
	int val;

	if (min >= max)
		return (NULL);
	result = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	val = min;
	while (val < max)
	{
		result[i] = val;
		i++;
		val++;
	}
	return (result);
}
