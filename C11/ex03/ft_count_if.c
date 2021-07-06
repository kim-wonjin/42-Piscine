/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:22:57 by wokim             #+#    #+#             */
/*   Updated: 2021/04/14 15:28:58 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int count;
	int i;

	i = -1;
	count = 0;
	while (++i < length)
	{
		if (f(tab[i]) != 0)
			count++;
	}
	return (count);
}
