/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:46:22 by wokim             #+#    #+#             */
/*   Updated: 2021/04/14 22:55:41 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tab_len(char **tab)
{
	int len;

	len = 0;
	while (tab[len])
		++len;
	return (len);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	len = ft_tab_len(tab);
	i = 1;
	while (i++ < len)
	{
		j = 0;
		while (++j < len)
		{
			if (ft_strcmp(tab[j - 1], tab[j]) > 0)
			{
				tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}
