/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:55:27 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/01 12:55:28 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_x(t_fdf *fdf, int i, int j)
{
	int	x;

	x = (fdf->cor[i][j]->x * cos(fdf->b) + (-fdf->cor[i][j]->y * sin(fdf->l) +
	fdf->cor[i][j]->z * cos(fdf->l)) * sin(fdf->b)) * cos(fdf->y) +
	(fdf->cor[i][j]->y * cos(fdf->l) + fdf->cor[i][j]->z * sin(fdf->l)) *
	sin(fdf->y) + (WIN_X / 2);
	return (x);
}

int		ft_count_y(t_fdf *fdf, int i, int j)
{
	int	y;

	y = -(fdf->cor[i][j]->x * cos(fdf->b) + (-fdf->cor[i][j]->y * sin(fdf->l) +
	fdf->cor[i][j]->z * cos(fdf->l)) * sin(fdf->b)) * sin(fdf->y) +
	(fdf->cor[i][j]->y * cos(fdf->l) + fdf->cor[i][j]->z * sin(fdf->l)) *
	cos(fdf->y) + (WIN_Y / 2);
	return (y);
}

void	ft_fill_draw(t_fdf *fdf, int i, int j)
{
	fdf->xy0.x0 = ft_count_x(fdf, i, j);
	fdf->xy0.y0 = ft_count_y(fdf, i, j);
	fdf->xy0.x1 = ft_count_x(fdf, i, j + 1);
	fdf->xy0.y1 = ft_count_y(fdf, i, j + 1);
	fdf->xy0.deltax = abs(fdf->xy0.x1 - fdf->xy0.x0);
	fdf->xy0.deltay = abs(fdf->xy0.y1 - fdf->xy0.y0);
	fdf->xy0.signx = fdf->xy0.x1 >= fdf->xy0.x0 ? 1 : -1;
	fdf->xy0.signy = fdf->xy0.y1 >= fdf->xy0.y0 ? 1 : -1;
	fdf->xy0.error = fdf->xy0.deltax - fdf->xy0.deltay;
	fdf->xy0.error2 = fdf->xy0.error * 2;
}

void	ft_fill_draw_next(t_fdf *fdf, int i, int j)
{
	fdf->xy1.x0 = ft_count_x(fdf, i, j);
	fdf->xy1.y0 = ft_count_y(fdf, i, j);
	fdf->xy1.x1 = ft_count_x(fdf, i + 1, j);
	fdf->xy1.y1 = ft_count_y(fdf, i + 1, j);
	fdf->xy1.deltax = abs(fdf->xy1.x1 - fdf->xy1.x0);
	fdf->xy1.deltay = abs(fdf->xy1.y1 - fdf->xy1.y0);
	fdf->xy1.signx = abs(fdf->xy1.x1 - fdf->xy1.x0);
	fdf->xy1.signy = abs(fdf->xy1.y1 - fdf->xy1.y0);
	fdf->xy1.error = fdf->xy1.deltax - fdf->xy1.deltay;
	fdf->xy1.error2 = fdf->xy1.error * 2;
}

void	ft_draw(t_fdf *fdf)
{
	while (fdf->i != fdf->len_y)
	{
		while (fdf->j != fdf->len_x)
		{
			if (fdf->j + 1 != fdf->len_x)
			{
				ft_fill_draw(fdf, fdf->i, fdf->j);
				ft_brezen(fdf, &fdf->xy0, fdf->i, fdf->j + 1);
			}
			if (fdf->i + 1 != fdf->len_y)
			{
				ft_fill_draw_next(fdf, fdf->i, fdf->j);
				ft_brezen(fdf, &fdf->xy1, fdf->i + 1, fdf->j);
			}
			fdf->j++;
		}
		fdf->j = 0;
		fdf->i++;
	}
}
