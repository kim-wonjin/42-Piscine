/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:35:27 by wokim             #+#    #+#             */
/*   Updated: 2021/04/14 11:34:04 by wokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF 1000000
# define READMAX 8000000

typedef struct	s_condition
{
	int			c_len;
	int			height;
	int			width;
	char		empty;
	char		obs;
	char		mark;
}				t_condition;

typedef struct	s_pos
{
	int			x;
	int			y;
	int			max;
}				t_pos;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_atoi(char *str);

void			total_process(char *input);
t_pos			*init_pos(void);

int				ft_conlen(char *input);
int				check_condition(char *input, int len);
char			*get_num(char *input, int len);
t_condition		*get_condition(char *input);
int				check_width(char *input, t_condition con, int width);

void			ft_strcat(char *dest, char *src, int *size, int buff_size);
void			escape_loop(int *size, char *input, int buf);
char			*ft_read(int f, int buff_size);

void			find_max(t_condition *con, char *input, t_pos *pos);
int				find_new_max(char *input, t_condition *con, int *spot,
																int current);
int				is_possible(char *input, int *spot, t_condition *con,
																int chk_size);
int				expand_square(char *input, int *spot, t_condition *con,
																int chk_size);
void			ft_mark(t_pos *pos, char *input, t_condition *con);
void			ft_put_result(char *str, int start);

#endif
