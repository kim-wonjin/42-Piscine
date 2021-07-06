/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:47:38 by jhong             #+#    #+#             */
/*   Updated: 2021/04/04 19:28:21 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

# define COL 0
# define ROW 1
# define TRUE 1
# define FALSE 0
# define UP 1
# define DOWN -1
# define LEFT 1
# define RIGHT -1

int g_size;

void	ft_first_process(int *input, int **map, int ***flag);
void	ft_row_max(int idx, int **map, int ***flag);
void	ft_col_max(int idx, int **map, int ***flag);
void	ft_col_row_1(int idx, int **map, int ***flag);
void	ft_put_map(int idx, int **map, int ***flag, int value);

int		**ft_last_process(int idx, int *input, int **map, int ***flag);
void	ft_total_process(int *input, int **map, int ***flag);

int		ft_check(int *input, int **map);
int		ft_col_count(int col_idx, int **map, int dir);
int		ft_row_count(int row_idx, int **map, int dir);

int		malloc_for_map(int ***map);
int		malloc_for_flag(int ****flag);
void	malloc_fot_free(int *input, int **map, int ***flag);

int		is_non_charset(char c, char *charset);
int		ft_word_count(char *str, char *charset);
int		ft_get_size(int word_size);
int		*ft_split(char *str, char *charset);
int		ft_count(int *input);

void	ft_putchar(char c);
void	ft_print_map(int **map);
int		ft_error(void);

#endif
