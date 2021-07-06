/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:56:14 by wokim             #+#    #+#             */
/*   Updated: 2021/04/14 23:04:20 by wokim            ###   ########.fr       */
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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[j - 1], tab[j]) > 0)
			{
				tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}
