/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:48:24 by wokim             #+#    #+#             */
/*   Updated: 2021/04/06 20:47:33 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_len(char *base)
{
	int already[256];
	int i;

	i = 0;
	while (i < 256)
		already[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (already[(int)base[i]] ||
			base[i] == '+' ||
			base[i] == '-' ||
			base[i] == ' ' ||
			('\t' <= base[i] && base[i] <= '\r'))
			return (0);
		already[(int)base[i++]] = 1;
	}
	return (i);
}

int		get_idx(char c, int len, char *base)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int result;
	int sign;
	int idx;
	int len;

	len = get_len(base);
	result = 0;
	sign = 1;
	if (len == 0 || len == 1)
		return (0);
	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		idx = get_idx(*(str++), len, base);
		if (idx == -1)
			break ;
		result *= len;
		result += (sign * idx);
	}
	return (result);
}
