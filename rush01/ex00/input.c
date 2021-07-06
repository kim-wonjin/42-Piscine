/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:58:07 by jhong             #+#    #+#             */
/*   Updated: 2021/04/04 19:32:07 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			is_non_charset(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (0);
		else if (c >= '1' && c <= '9')
			return (1);
		charset++;
	}
	return (2);
}

int			ft_word_count(char *str, char *charset)
{
	int		cnt;
	int		idx;

	cnt = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (is_non_charset(str[idx], charset) == 1)
		{
			if (!is_non_charset(str[idx + 1], charset) || str[idx + 1] == '\0')
				cnt++;
			else if (is_non_charset(str[idx + 1], charset) != 0)
				return (0);
		}
		else if (is_non_charset(str[idx], charset) == 2)
			return (0);
		idx++;
	}
	return (cnt);
}

int			ft_get_size(int word_size)
{
	int		map_size;

	map_size = 0;
	if (word_size == 16)
		map_size = 4;
	else if (word_size == 20)
		map_size = 5;
	else if (word_size == 24)
		map_size = 6;
	else if (word_size == 28)
		map_size = 7;
	else if (word_size == 32)
		map_size = 8;
	else if (word_size == 36)
		map_size = 9;
	else
		return (0);
	return (map_size);
}

int			*ft_split(char *str, char *charset)
{
	int		int_idx;
	int		word_size;
	int		idx;
	int		*str_int;

	word_size = ft_word_count(str, charset);
	if (ft_get_size(word_size) == 0)
		return (0);
	str_int = (int*)malloc(sizeof(int) * (word_size));
	int_idx = -1;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (is_non_charset(str[idx], charset) == 1)
			str_int[++int_idx] = str[idx] - '0';
		idx++;
	}
	return (str_int);
}

int			ft_count(int *input)
{
	int		cnt;

	cnt = 0;
	while (input[cnt] >= 1 && input[cnt] <= 9)
		cnt++;
	return (cnt);
}
