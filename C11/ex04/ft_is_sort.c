/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:29:38 by wokim             #+#    #+#             */
/*   Updated: 2021/04/14 17:12:24 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int flag;

	flag = 1;
	i = -1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
		{
			flag = 0;
			break ;
		}
	}
	i = -1;
	if (flag == 0)
	{
		while (++i < length - 1)
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
		flag = 1;
	}
	return (flag);
}
