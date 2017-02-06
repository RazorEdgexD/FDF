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



void	ft_draw(t_fdf *fdf)
{
	double	xx = 0;
	double	yy = 0;
	double 	x_n = 0;
	double	y_n = 0;

	while (fdf->i != fdf->len_y)
	{
		while (fdf->j != fdf->len_x)
		{
			xx = (fdf->cor[fdf->i][fdf->j]->x) * cos(L) + (-(fdf->cor[fdf->i][fdf->j]->y) * sin(L) + -fdf->cor[fdf->i][fdf->j]->z * cos(B)) * sin(B) + (WIN_X / 2);
			yy = ((fdf->cor[fdf->i][fdf->j]->y) * cos(B)) + -fdf->cor[fdf->i][fdf->j]->z * sin(B) + (WIN_Y / 2);
			if (fdf->j + 1 != fdf->len_x)
			{
				x_n = (fdf->cor[fdf->i][fdf->j + 1]->x) * cos(L) + (-(fdf->cor[fdf->i][fdf->j + 1]->y) * sin(L) + -fdf->cor[fdf->i][fdf->j + 1]->z * cos(B)) * sin(B) + (WIN_X / 2);
				y_n = ((fdf->cor[fdf->i][fdf->j + 1]->y) * cos(B)) + -fdf->cor[fdf->i][fdf->j + 1]->z * sin(B) + (WIN_Y / 2);
				ft_brezen(xx, yy, x_n, y_n , fdf->cor[fdf->i][fdf->j]->color, fdf);
			}
			if (fdf->i + 1 != fdf->len_y)
			{
				x_n = (fdf->cor[fdf->i + 1][fdf->j]->x) * cos(L) + (-(fdf->cor[fdf->i + 1][fdf->j]->y) * sin(L) + -fdf->cor[fdf->i + 1][fdf->j]->z * cos(B)) * sin(B) + (WIN_X / 2);
				y_n = ((fdf->cor[fdf->i + 1][fdf->j]->y) * cos(B)) + -fdf->cor[fdf->i + 1][fdf->j]->z * sin(B) + (WIN_Y / 2);
				ft_brezen(xx, yy, x_n, y_n , fdf->cor[fdf->i][fdf->j]->color, fdf);
			}
			fdf->j++;
		}
		fdf->j = 0;
		fdf->i++;
	}
}
