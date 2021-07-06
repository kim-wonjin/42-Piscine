/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:28:31 by wokim             #+#    #+#             */
/*   Updated: 2021/03/29 15:28:34 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_arr[10];

void	rec(int front, int n, int num)
{
	int i;

	if (num == n)
	{
		write(1, g_arr, n);
		write(1, ", ", 2);
		return ;
	}
	if (front == 9)
		return ;
	i = front + 1;
	while (i <= 10 - n + num)
	{
		g_arr[num] = '0' + i;
		rec(i, n, num + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int i;
	int c;

	i = 0;
	while (i < 10 - n)
	{
		g_arr[0] = '0' + i;
		rec(i, n, 1);
		i++;
	}
	if (i == 10 - n)
	{
		while (i < 10)
		{
			c = '0' + i++;
			write(1, &c, 1);
		}
	}
}
