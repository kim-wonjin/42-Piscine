/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:08:55 by wokim             #+#    #+#             */
/*   Updated: 2021/03/31 21:44:25 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		hexa(unsigned char c)
{
	c = '0' + c;
	if (c > '9')
		c += 39;
	write(1, &c, 1);
}

void		change(unsigned char c)
{
	write(1, "\\", 1);
	hexa((int)c / 16);
	hexa((int)c % 16);
}

void		ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(' ' <= str[i] && str[i] <= '~'))
			change(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
