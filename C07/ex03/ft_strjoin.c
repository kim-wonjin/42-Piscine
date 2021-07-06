/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:39:47 by wokim             #+#    #+#             */
/*   Updated: 2021/04/12 23:05:24 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strcat(char *dst, char *src)
{
	while (*src)
		*(dst++) = *(src++);
	return (dst);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char		*r;
	char		*p;
	int			word;
	int			i;

	if (size == 0)
	{
		r = ((char*)malloc(1));
		r[0] = 0;
		return (r);
	}
	word = 0;
	i = 0;
	while (i < size)
		word += ft_strlen(strs[i++]);
	r = (char*)malloc(sizeof(char) * (word + (size - 1) * ft_strlen(sep) + 1));
	p = ft_strcat(r, strs[0]);
	i = 1;
	while (i < size)
	{
		p = ft_strcat(p, sep);
		p = ft_strcat(p, strs[i++]);
	}
	*p = 0;
	return (r);
}
