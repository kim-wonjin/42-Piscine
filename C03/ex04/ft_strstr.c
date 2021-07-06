/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:55:32 by wokim             #+#    #+#             */
/*   Updated: 2021/04/05 16:18:15 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *p_s;
	char *p_f;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			p_s = str;
			p_f = to_find;
			while (*p_f)
			{
				p_s++;
				p_f++;
				if (*p_f == '\0')
					return (str);
				if (*p_s != *p_f)
					break ;
			}
		}
		str++;
	}
	return (0);
}
