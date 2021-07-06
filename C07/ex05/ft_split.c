/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:55:28 by wokim             #+#    #+#             */
/*   Updated: 2021/04/12 23:01:17 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

long long	word_count(char *str, char *charset)
{
	long long count;

	count = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			count++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
		str++;
	}
	return (count);
}

void		ft_strcpy(char *dst, char *a, char *b)
{
	while (a < b)
		*(dst++) = *(a++);
	*dst = 0;
}

char		**ft_split(char *str, char *charset)
{
	char		**result;
	long long	idx;
	char		*p;

	result = (char**)malloc(sizeof(char*) * word_count(str, charset) + 1);
	idx = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			p = str;
			while (*str && !is_charset(*str, charset))
				str++;
			result[idx] = (char*)malloc(str - p + 1);
			ft_strcpy(result[idx++], p, str);
		}
		str++;
	}
	result[idx] = 0;
	return (result);
}
