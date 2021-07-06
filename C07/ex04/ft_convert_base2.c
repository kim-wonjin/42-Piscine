/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:29:50 by wokim             #+#    #+#             */
/*   Updated: 2021/04/13 05:16:55 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_base_digit(unsigned int nbr, unsigned int baselen)
{
	unsigned int num;

	num = 1;
	while (nbr >= baselen)
	{
		num *= baselen;
		nbr /= baselen;
	}
	return (num);
}

int				get_digit(int base_digit, int baselen)
{
	int	i;

	i = 0;
	while (base_digit > 1)
	{
		base_digit /= baselen;
		i++;
	}
	return (i);
}

char			*allocate_result(int digit, int nbr)
{
	char	*result;

	if (nbr < 0)
		result = malloc(sizeof(char) * digit + 2);
	else
		result = malloc(sizeof(char) * digit + 1);
	if (!result)
		return (NULL);
	else
		return (result);
}

char			*convert_str(int nbr, int baselen, char *base)
{
	unsigned int	base_digit;
	int				digit;
	int				i;
	char			*result;
	int				temp;

	temp = nbr;
	if (nbr < 0)
		temp = nbr * -1;
	base_digit = ft_base_digit(temp, baselen);
	digit = get_digit(base_digit, baselen);
	result = allocate_result(digit, nbr);
	i = 0;
	if (nbr < 0)
		result[i++] = '-';
	while (base_digit > 1)
	{
		result[i++] = base[(temp / base_digit) % baselen];
		temp = temp % base_digit;
		base_digit /= baselen;
	}
	result[i++] = base[temp % baselen];
	result[i] = '\0';
	return (result);
}
