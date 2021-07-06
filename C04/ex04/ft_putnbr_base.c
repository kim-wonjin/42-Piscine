/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:48:53 by wokim             #+#    #+#             */
/*   Updated: 2021/04/07 10:48:36 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int nbr, int len, char *base)
{
	if (!nbr)
		return ;
	print(nbr / len, len, base);
	write(1, &base[nbr % len], 1);
}

int		get_len(char *base)
{
	int already[256];
	int i;

	i = 0;
	while (i < 256)
		already[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (already[(int)base[i]] ||
			base[i] == '+' ||
			base[i] == '-')
			return (0);
		already[(int)base[i++]] = 1;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long long	tmp;

	len = get_len(base);
	if (len == 0 || len == 1)
		return ;
	tmp = nbr;
	if (tmp < 0)
	{
		tmp *= -1;
		write(1, "-", 1);
	}
	print(tmp / len, len, base);
	write(1, &base[tmp % len], 1);
}
