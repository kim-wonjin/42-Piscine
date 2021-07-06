/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:36:23 by wokim             #+#    #+#             */
/*   Updated: 2021/04/07 14:41:38 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int			main(int argc, char *argv[])
{
	int i;

	i = argc - 1;
	if (argc > 1)
	{
		while (i > 0)
		{
			putstr(argv[i]);
			write(1, "\n", 1);
			i--;
		}
	}
	return (0);
}
