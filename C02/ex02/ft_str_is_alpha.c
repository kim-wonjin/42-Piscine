/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:26:49 by wokim             #+#    #+#             */
/*   Updated: 2021/03/31 11:44:20 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (122 < str[i] || str[i] < 65)
			return (0);
		if (90 < str[i] && str[i] < 97)
			return (0);
		i++;
	}
	return (1);
}
