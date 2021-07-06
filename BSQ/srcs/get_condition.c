/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:51:23 by wokim             #+#    #+#             */
/*   Updated: 2021/04/13 21:20:16 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			ft_conlen(char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		i++;
		if (input[i] == '\n')
			return (i + 1);
	}
	return (i);
}

int			check_condition(char *input, int len)
{
	int i;
	int temp;

	i = -1;
	while (input[++i] != '\n')
		if (input[i] < ' ' || input[i] > '~')
			return (0);
	i = 0;
	temp = len - 5;
	if (len < 5)
		return (0);
	if ((input[len - 3] == input[len - 2]) ||
			(input[len - 2] == input[len - 4]) ||
			(input[len - 4] == input[len - 3]))
		return (0);
	if (temp == 0 && input[0] >= '0' && input[0] <= '9')
		return (1);
	while (i <= temp)
	{
		if (input[i] > '9' || input[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

char		*get_num(char *input, int len)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(*temp) * len);
	while (i <= len)
	{
		temp[i] = input[i];
		i++;
	}
	return (temp);
}

t_condition	*get_condition(char *input)
{
	t_condition	*c;
	int			i;
	char		*str;
	int			len;

	c = NULL;
	len = ft_conlen(input);
	if (check_condition(input, len) == 1)
	{
		str = (char *)malloc(sizeof(*str) * len);
		c = (t_condition*)malloc(sizeof(t_condition) * 1);
		i = 0;
		str = get_num(input, len - 5);
		c->height = ft_atoi(str);
		c->c_len = len;
		c->empty = input[len - 4];
		c->obs = input[len - 3];
		c->mark = input[len - 2];
	}
	return (c);
}

int			check_width(char *input, t_condition con, int width)
{
	int	i;
	int	check;
	int	line;

	i = con.c_len - 1;
	check = 0;
	line = 0;
	while (input[++i])
		if (input[i] == '\n')
		{
			if (width != -1 && width != check)
				return (-1);
			width = check;
			line++;
			check = 0;
		}
		else if (input[i] != con.obs && input[i] != con.empty)
			return (-1);
		else if (check == 2147483647)
			return (-1);
		else
			check++;
	if (line == con.height)
		return (width);
	return (-1);
}
