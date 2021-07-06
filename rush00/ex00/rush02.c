/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:50:02 by wokim             #+#    #+#             */
/*   Updated: 2021/03/28 18:37:14 by juyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

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
		print_line('A', 'B', 'A', x);
		if (y != 1)
		{
			mid('B', x, y);
			print_line('C', 'B', 'C', x);
		}
	}
}
