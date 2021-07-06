/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:20:09 by wokim             #+#    #+#             */
/*   Updated: 2021/04/14 11:06:26 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int argc, char **argv)
{
	int		i;
	char	*input;
	int		f;

	input = NULL;
	i = 0;
	if (argc != 1)
		while (++i < argc)
		{
			f = open(argv[i], O_RDONLY);
			if (f > 0)
			{
				input = ft_read(f, READMAX);
				total_process(input);
				close(f);
			}
			else
				ft_putstr("map error\n");
		}
	else
	{
		input = ft_read(0, BUFF);
		total_process(input);
	}
	return (0);
}

void	total_process(char *input)
{
	t_condition	*con;
	t_pos		*pos;

	con = get_condition(input);
	pos = init_pos();
	if (con)
	{
		con->width = check_width(input, *con, -1);
		if (con->width > 0)
		{
			find_max(con, input, pos);
			ft_mark(pos, input, con);
			ft_put_result(input, con->c_len);
			free(input);
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("map error\n");
}

t_pos	*init_pos(void)
{
	t_pos *temp;

	temp = (t_pos *)malloc(sizeof(t_pos));
	if (temp)
	{
		temp->x = 0;
		temp->y = 0;
		temp->max = 0;
	}
	return (temp);
}
