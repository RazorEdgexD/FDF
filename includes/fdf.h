/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:51:22 by aosobliv          #+#    #+#             */
/*   Updated: 2017/01/19 18:28:10 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define rad (180 / PI)
# define is_digit(c) ((((c) >= '0') && ((c) <= '9')) ? 1 : 0)
// # define STRING (s[i] == 'A' || s[i] == 'B' || s[i] == 'C' ||s[i] == 'D' || s[i] == 'E' || s[i] == 'F' || s[i] == 'x' || s[i] == 'a' || s[i] == 'b' || s[i] == 'c' || s[i] == 'd' || s[i] == 'e' || s[i] == 'f' || s[i] == '0') || Is_Digit(s[i])

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	int				center_x;
	int				center_y;
	int				len_x;
	int				len_y;
	int				scale;
	int				i;
	int				j;
	int				k;

	int				***arr_i;
	char			***tmp;
}					t_fdf;

void				ft_check_and_add_coord(int fd1, int fd2, t_fdf fdf);
int					ft_atoi_base(char *str, int base);

void				ft_arguments_error(void);
void				ft_open_file_error(void);
void				ft_malloc_error(void);
void				ft_line_len_error(void);
void				ft_number_error(void);

#endif
