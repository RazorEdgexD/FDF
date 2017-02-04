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

void	ft_draw(t_fdf fdf)
{

//	double	x = 0;

	double	xx = 0;
	double	yy = 0;

	double 	x_n = 0;
	double	y_n = 0;
	int		i;

	i = 1;
	while (fdf.cor->next)
	{
		if (i == fdf.len_x)
			i = 1;
		else
		{
//	x = fdf.cor->x * 25;
//	xx = x * cos(RAD * 45)  + sin(RAD * 45) * (-fdf.cor->y * 25 * sin(45 * RAD) + fdf.cor->z * 25 * cos(RAD * 45)) ;
//	yy = fdf.cor->y * 25 * cos(RAD * 45) + fdf.cor->z * 25 * sin(RAD * 45);
//	mlx_pixel_put(fdf.mlx, fdf.win, -xx + 500, -yy + 500, fdf.cor->color);
		xx = (fdf.cor->x) * cos(L) + (-(fdf.cor->y) * sin(L) + -fdf.cor->z * cos(B)) * sin(B);
		yy = (fdf.cor->y * cos(B)) + -fdf.cor->z * sin(B);
		x_n = (fdf.cor->next->x) * cos(L) + (-(fdf.cor->next->y) * sin(L) + -fdf.cor->next->z * cos(B)) * sin(B);
		y_n = (fdf.cor->next->y * cos(B)) + -fdf.cor->next->z * sin(B);
//		printf("%f | %f ====== %f | %f\n", xx, yy,x_n, y_n);
		ft_brezen(xx + 500, yy + 500, x_n + 500, y_n + 500, fdf.cor->color, fdf);
	//	printf("X_DRAW = %f, Y_DRAW = %f\n", xx, yy);
	//	mlx_pixel_put(fdf.mlx, fdf.win, xx + 1500, yy + 500, fdf.cor->color);

	//	printf("TEST DRAW X=%d Y=%d DRAW_X=%d DRAW_Y=%d, new\n", fdf.cor->x, fdf.cor->y, fdf.center_x - fdf.cor->x + new_y, -fdf.cor->y + fdf.center_y + new_y);
		i++;
		}
		fdf.cor = fdf.cor->next;
	}
}
