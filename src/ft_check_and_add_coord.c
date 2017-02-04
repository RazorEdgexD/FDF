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
	fdf->scalX = WIN_X / 2 / fdf->len_x;
	fdf->scalY = WIN_Y / 2 / fdf->len_y;
	if (fdf->len_x == 500)
		fdf->scalX = 1;
	if (fdf->len_y == 500)
		fdf->scalY = 1;
	fdf->scalZ = (fdf->scalX + fdf->scalY) / 4;
	if (fdf->scalY == 1 && fdf->scalX ==1)
		fdf->scalZ = 1;
}

void		ft_add_coord(int fd2, t_fdf *fdf)
{
	char	*line;
	char	***tmp;

	tmp = (char***)malloc(sizeof(char**) * (fdf->len_y + 1));
	fdf->tmp_cor = (t_cor*)malloc(sizeof(t_cor));
	fdf->cor = fdf->tmp_cor;
	while (get_next_line(fd2, &line) == 1)
	{
		tmp[fdf->i] = ft_strsplit(line, 32);
		while (tmp[fdf->i][fdf->j] != NULL)
		{
			fdf->tmp_cor->x = fdf->j * fdf->scalX;
			fdf->tmp_cor->y = fdf->i * fdf->scalY;
			fdf->tmp_cor->z = (double)ft_atoi(tmp[fdf->i][fdf->j]) * fdf->scalZ;
			ft_take_color(tmp[fdf->i][fdf->j], fdf->tmp_cor);
			fdf->tmp_cor->next = (t_cor*)malloc(sizeof(t_cor));
			printf("%d========================%d\n", fdf->i, fdf->j);
			printf("x=%f|y=%f|z=%f\n", fdf->tmp_cor->x, fdf->tmp_cor->y ,fdf->tmp_cor->z);
			fdf->tmp_cor = fdf->tmp_cor->next;
			fdf->tmp_cor->next = NULL;
			fdf->j++;
		}
		fdf->j = 0;
		fdf->i++;
	}
//	while (fdf->cor->next)
//	{
//		printf("x=%d y=%d z=%d color=%d red=%d green=%d blue=%d\n", fdf->cor->x, fdf->cor->y, fdf->cor->z, fdf->cor->color, fdf->cor->red, fdf->cor->green, fdf->cor->blue);
//		fdf->cor = fdf->cor->next;
//	}
}

void		ft_check_and_add_coord(int fd1, int fd2, t_fdf *fdf)
{
	fdf->j = 0;
	fdf->i = 0;
	ft_len_plus_color_check(fd1, fdf);
	ft_add_scale(fdf);
	ft_add_coord(fd2, fdf);
}
