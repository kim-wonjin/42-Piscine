/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:50:02 by wokim             #+#    #+#             */
/*   Updated: 2021/03/29 18:52:09 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */void	ft_putchar(char a);

void	print_line(char f, char m, char l, int x)
{
	int i;

	i = 0;
	ft_putchar(f);
	if (x != 1)
	{
		while (i < x - 2)
		{
			ft_putchar(m);
			i++;
		}
		ft_putchar(l);
	}
	ft_putchar('\n');
}

void	mid(char m, int x, int y)
{
	int i;

	i = 0;
	while (i < y - 2)
	{
		print_line(m, ' ', m, x);
		i++;
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		print_line('o', '-', 'o', x);
		if (y != 1)
		{
			mid('|', x, y);
			print_line('o', '-', 'o', x);
		}
	}
}
