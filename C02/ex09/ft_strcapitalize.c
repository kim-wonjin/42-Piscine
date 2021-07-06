/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:51:38 by wokim             #+#    #+#             */
/*   Updated: 2021/03/31 17:06:27 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int		small(char c)
{
	if (97 <= c && c <= 122)
		return (1);
	return (0);
}

int		big(char c)
{
	if (65 <= c && c <= 90)
		return (1);
	return (0);
}

int		other(char c)
{
	if (num(c))
		return (0);
	if (big(c))
		return (0);
	if (small(c))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int word_f;

	i = 0;
	while (str[i])
	{
		if (i == 0 || other(str[i - 1]))
			word_f = 1;
		else
			word_f = 0;
		if (word_f && small(str[i]))
			str[i] -= 32;
		else if (!word_f && big(str[i]))
			str[i] += 32;
		++i;
	}
	return (str);
}
