/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:54:23 by aosobliv          #+#    #+#             */
/*   Updated: 2017/01/26 16:54:25 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_check_number_and_color(char *s)
{
	int i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '-')
			i++;
		if (!IS_DIGIT(s[i]))
		{
			if (s[i] == ',')
			{
				i++;
				while (s[i] != '\0')
				{
					if ((s[i] == 'A' || s[i] == 'B' || s[i] == 'C' ||
					s[i] == 'D' || s[i] == 'E' || s[i] == 'F' || s[i] == 'x'
					|| s[i] == 'a' || s[i] == 'b' || s[i] == 'c' || s[i] == 'd'
					|| s[i] == 'e' || s[i] == 'f' || s[i] == '0')
					|| IS_DIGIT(s[i]))
						i++;
					else
						ft_number_error();
				}
				break ;
			}
			else
				ft_number_error();
		}
	}
}

void		ft_len_plus_color_check(int fd, t_fdf *fdf)
{
	int		len_x;
	char	*line;
	char	**split;
	int		tmp_len_x;

	len_x = 0;
	fdf->len_y = 0;
	tmp_len_x = 0;
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, 32);
		while (split[len_x] != NULL)
		{
			ft_check_number_and_color(split[len_x]);
			len_x++;
			tmp_len_x++;
		}
		if (len_x != tmp_len_x / (fdf->len_y + 1))
			ft_line_len_error();
		fdf->len_x = len_x;
		len_x = 0;
		fdf->len_y++;
	}
}

void		ft_add_scale(t_fdf *fdf)
{
	fdf->scalall = 1;
	fdf->scalx = WIN_X / 2 / fdf->len_x;
	fdf->scaly = WIN_Y / 2 / fdf->len_y;
	if (fdf->len_x == 500)
		fdf->scalx = 2;
	if (fdf->len_y == 500)
		fdf->scaly = 2;
	fdf->scalz = (fdf->scalx + fdf->scaly) / fdf->scaly * 5;
}

void		ft_add_coord(int fd2, t_fdf *fdf)
{
	char	*line;
	char	***tmp;

	fdf->cor = (t_cor***)malloc(sizeof(t_cor**) * (fdf->len_y + 1));
	tmp = (char***)malloc(sizeof(char**) * (fdf->len_y + 1));
	while (get_next_line(fd2, &line) == 1)
	{
		fdf->cor[fdf->i] = (t_cor**)malloc(sizeof(t_cor*) * (fdf->len_x + 1));
		tmp[fdf->i] = ft_strsplit(line, 32);
		while (tmp[fdf->i][fdf->j] != NULL)
		{
			fdf->cor[fdf->i][fdf->j] = (t_cor*)malloc(sizeof(t_cor));
			fdf->cor[fdf->i][fdf->j]->x = fdf->j * fdf->scalx * fdf->scalall;
			fdf->cor[fdf->i][fdf->j]->y = fdf->i * fdf->scaly * fdf->scalall;
			fdf->cor[fdf->i][fdf->j]->z = -(double)ft_atoi(tmp[fdf->i][fdf->j])
			* fdf->scalz * fdf->scalall;
			ft_take_color(tmp[fdf->i][fdf->j], fdf->cor[fdf->i][fdf->j]);
			fdf->j++;
		}
		fdf->j = 0;
		fdf->i++;
	}
	fdf->i = 0;
	fdf->j = 0;
}

void		ft_check_and_add_coord(int fd1, int fd2, t_fdf *fdf)
{
	fdf->j = 0;
	fdf->i = 0;
	fdf->l = 60 * RAD;
	fdf->b = -70.5 * RAD;
	fdf->y = 0 * RAD;
	printf("xyi pizda l =%f b=%f y=%f\n", fdf->l, fdf->b, fdf->y);
	ft_len_plus_color_check(fd1, fdf);
	ft_add_scale(fdf);
	ft_add_coord(fd2, fdf);
	fdf->center_x = (fdf->scalx * fdf->len_x) / 2;
	fdf->center_y = (fdf->scaly * fdf->len_y) / 4;
}
