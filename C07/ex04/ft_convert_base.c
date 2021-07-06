/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:27:51 by wokim             #+#    #+#             */
/*   Updated: 2021/04/13 05:16:24 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*convert_str(int nbr, int baselen, char *base);

int				is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 12))
		return (1);
	return (0);
}

unsigned int	check_base(char *base)
{
	char	*ptr;
	char	*base_cmp;
	int		i;

	i = 0;
	ptr = base;
	while (*ptr)
	{
		base_cmp = ptr + 1;
		if (*ptr == '+' || *ptr == '-' || is_space(*ptr))
			return (0);
		while (*base_cmp)
		{
			if (*ptr == *base_cmp)
				return (0);
			base_cmp++;
		}
		ptr++;
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (i);
}

int				ft_sign(char *str)
{
	unsigned int	sign;

	sign = 1;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	return (sign);
}

void			ft_atoi_base(char *nbr, char *base, int baselen, int *num)
{
	int			i;
	char		*ptr;

	while (is_space(*nbr))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
		nbr++;
	while (*nbr)
	{
		ptr = base - 1;
		i = 0;
		while (*++ptr)
		{
			if (*nbr == *ptr)
			{
				*num = *num * baselen + i;
				break ;
			}
			i++;
		}
		if (!*ptr)
			break ;
		nbr++;
	}
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		base_from_len;
	int		base_to_len;
	char	*result;

	num = 0;
	base_from_len = check_base(base_from);
	base_to_len = check_base(base_to);
	if (base_from_len > 0 && base_to_len > 0)
	{
		ft_atoi_base(nbr, base_from, base_from_len, &num);
		num *= ft_sign(nbr);
		result = convert_str(num, base_to_len, base_to);
		return (result);
	}
	else
		return (0);
}
