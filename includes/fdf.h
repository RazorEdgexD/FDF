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
# define WIN_X 1600
# define WIN_Y 1200
# define RAD (2 * M_PI / 360)
# define IS_DIGIT(c) ((((c) >= '0') && ((c) <= '9')) ? 1 : 0)

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

typedef	struct		s_cor
{
	double			x;
	double			y;
	double			z;
	int				red;
	int				green;
	int				blue;
	int				color;
}					t_cor;

typedef struct		s_draw
{
	int				deltax;
	int				deltay;
	int				signx;
	int				signy;
	int				error;
	int				error2;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_draw;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				center_x;
	int				center_y;
	int				len_x;
	int				len_y;
	int				scalx;
	int				scaly;
	int				scalz;
	int				i;
	int				j;
	int				k;
	int				l;
	int				b;
	int				y;
	struct s_cor	***cor;
	struct s_draw	xy0;
	struct s_draw	xy1;
}					t_fdf;

void				ft_check_and_add_coord(int fd1, int fd2, t_fdf *fdf);
int					ft_atoi_base(char *str, int base);
void				ft_take_color(char *str, t_cor *tmp);
void				ft_brezen(t_fdf *fdf, t_draw *draw, int i, int j);
void				ft_draw(t_fdf *fdf);

void				ft_arguments_error(void);
void				ft_open_file_error(void);
void				ft_malloc_error(void);
void				ft_line_len_error(void);
void				ft_number_error(void);

#endif
