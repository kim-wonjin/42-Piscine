/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:24:11 by wokim             #+#    #+#             */
/*   Updated: 2021/04/15 00:47:42 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

void	rec(int nb)
{
	char c;

	if (nb == 0)
		return ;
	rec(nb / 10);
	c = '0' + nb % 10;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char c;

	if (nb < 0)
	{
		write(1, "-", 1);
		rec(-(nb / 10));
		c = '0' - nb % 10;
	}
	else
	{
		rec(nb / 10);
		c = '0' + nb % 10;
	}
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int ret;
	int sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		++str;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		ret *= 10;
		ret += (sign * (*(str++) - '0'));
	}
	return (ret);
}

void	operate(int a, int b, char op)
{
	if (op == '+')
		ft_putnbr(sum(a, b));
	if (op == '-')
		ft_putnbr(sub(a, b));
	if (op == '*')
		ft_putnbr(mul(a, b));
	if (op == '/')
		ft_putnbr(div(a, b));
	if (op == '%')
		ft_putnbr(mod(a, b));
}

int		main(int argc, char *argv[])
{
	int		a;
	int		b;
	char	op;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		op = *argv[2];
		if (!(op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
				|| argv[2][1])
		{
			write(1, "0\n", 2);
			return (0);
		}
		if (b == 0 && op == '/')
			write(1, "Stop : division by zero", 23);
		else if (b == 0 && op == '%')
			write(1, "Stop : modulo by zero", 21);
		else
			operate(a, b, op);
		write(1, "\n", 1);
	}
	return (0);
}
