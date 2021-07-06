/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:53:06 by wokim             #+#    #+#             */
/*   Updated: 2021/03/27 18:11:04 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	next(char *arr, int a, int b)
{
	write(1, arr, 7);
	if (arr[b] == '9')
	{
		arr[a]++;
		arr[b] = '0';
	}
	else
		arr[b]++;
}

void	ft_print_comb2(void)
{
	char arr[7];

	arr[0] = '0';
	arr[1] = '0';
	arr[2] = ' ';
	arr[5] = ',';
	arr[6] = ' ';
	while (!(arr[0] == '9' && arr[1] == '8'))
	{
		arr[3] = arr[0];
		arr[4] = arr[1] + 1;
		if (arr[1] == '9')
		{
			arr[3]++;
			arr[4] = '0';
		}
		while (!(arr[3] == '9' && arr[4] == '9'))
			next(arr, 3, 4);
		next(arr, 0, 1);
	}
	write(1, "98 99", 5);
}
