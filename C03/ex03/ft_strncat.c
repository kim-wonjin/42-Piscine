/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:25:54 by wokim             #+#    #+#             */
/*   Updated: 2021/04/01 12:45:24 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*p;

	i = 0;
	p = dest;
	while (*p)
		p++;
	while (*src && i < nb)
	{
		*p = *src;
		src++;
		p++;
		i++;
	}
	*p = '\0';
	return (dest);
}
