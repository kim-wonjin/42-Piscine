/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:19:19 by wokim             #+#    #+#             */
/*   Updated: 2021/04/08 12:27:28 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rec(int index, int result)
{
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (rec((index - 1), result) + rec((index - 2), result));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (rec(index, 0));
}
