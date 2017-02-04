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

void	ft_add_to_draw(t_fdf *fdf)
{
	t_cor	*tmp;
	t_draw	*draw;
	int		i;

	fdf->draw = (t_draw*)malloc(sizeof(t_draw));
	fdf->tmp_cor = (t_cor*)malloc(sizeof(t_cor));
	fdf->tmp_cor = fdf->cor;
	draw = (t_draw*)malloc(sizeof(t_draw));
	fdf->draw = draw;
	tmp = (t_cor*)malloc(sizeof(t_draw));
	tmp = fdf->cor;
	i = fdf->len_x;
	while (i != 0)
	{
		tmp = tmp->next;
		i--;
	}
	while (tmp->next && fdf->tmp_cor->next)
	{
		draw->x1 = (fdf->tmp_cor->x - WIN_X / 2) * cos(L) + (-(fdf->tmp_cor->y) * sin(L) + -fdf->tmp_cor->z * cos(B)) * sin(B) + (WIN_X / 3 * 2);
		draw->x2 = ((tmp->y - WIN_Y / 2) * cos(B)) + -tmp->z * sin(B) + (WIN_Y / 3 * 2);
		draw->y1 = (fdf->tmp_cor->x - WIN_X / 2) * cos(L) + (-(fdf->tmp_cor->y) * sin(L) + -fdf->tmp_cor->z * cos(B)) * sin(B) + (WIN_X / 3 * 2);
		draw->y2 = ((tmp->next->y - WIN_Y / 2) * cos(B)) + -tmp->next->z * sin(B) + (WIN_Y / 3 * 2);
		draw->deltaX = fabs(draw->x2 - draw->x1);
		draw->deltaY = fabs(draw->y2 - draw->y1);
		printf("tmp_cor_x=%f tmp_cor_y=%f  tmp_x=%f tmp_y=%f\n", fdf->tmp_cor->x, fdf->tmp_cor->y, tmp->x, tmp->y);
		draw->signX = draw->x1 < draw->x2 ? 1 : -1;
		draw->signY = draw->y2 < draw->y2 ? 1 : -1;
		draw->error = draw->deltaX - draw->deltaY;
		draw->error2 = draw->error * 2;
		draw->next = (t_draw*)malloc(sizeof(t_draw));
		printf("deltaX=%d deltaY=%d signX=%d signY=%d error=%d\n", draw->deltaX, draw->deltaY, draw->signX, draw->signY, draw->error);
		draw = draw->next;
		draw->next = NULL;
		tmp = tmp->next;
		fdf->tmp_cor = fdf->tmp_cor->next;
	}
}

void	ft_draw(t_fdf *fdf)
{

//	double	x = 0;

	double	xx = 0;
	double	yy = 0;

	double 	x_n = 0;
	double	y_n = 0;
	int		i;

	i = 1;
	ft_add_to_draw(fdf);
	while (fdf->draw->next->next)
	{
		printf("%s\n", "HI");
		drawLine(fdf->draw, fdf);
		fdf->draw = fdf->draw->next;
	}
	while (fdf->cor->next)
	{
		if (i == fdf->len_x)
			i = 1;
		else
		{
//	x = fdf->cor->x * 25;
//	xx = x * cos(RAD * 45)  + sin(RAD * 45) * (-fdf->cor->y * 25 * sin(45 * RAD) + fdf->cor->z * 25 * cos(RAD * 45)) ;
//	yy = fdf->cor->y * 25 * cos(RAD * 45) + fdf->cor->z * 25 * sin(RAD * 45);
//	mlx_pixel_put(fdf.mlx, fdf.win, -xx + 500, -yy + 500, fdf->cor->color);
		xx = (fdf->cor->x - WIN_X / 2) * cos(L) + (-(fdf->cor->y) * sin(L) + -fdf->cor->z * cos(B)) * sin(B) + (WIN_X / 3 * 2);
		yy = ((fdf->cor->y - WIN_Y / 2) * cos(B)) + -fdf->cor->z * sin(B) + (WIN_Y / 3 * 2);
		x_n = (fdf->cor->next->x - WIN_X / 2) * cos(L) + (-(fdf->cor->next->y) * sin(L) + -fdf->cor->next->z * cos(B)) * sin(B) + (WIN_X / 3 * 2);
		y_n = ((fdf->cor->next->y - WIN_Y / 2) * cos(B)) + -fdf->cor->next->z * sin(B) + (WIN_Y / 3 * 2);
//		printf("%f | %f ====== %f | %f\n", xx, yy,x_n, y_n);
		ft_brezen(xx, yy, x_n, y_n , fdf->cor->color, fdf);
	//	printf("X_DRAW = %f, Y_DRAW = %f\n", xx, yy);
	//	mlx_pixel_put(fdf.mlx, fdf.win, xx + 1500, yy + 500, fdf->cor->color);

	//	printf("TEST DRAW X=%d Y=%d DRAW_X=%d DRAW_Y=%d, new\n", fdf->cor->x, fdf->cor->y, fdf.center_x - fdf->cor->x + new_y, -fdf->cor->y + fdf.center_y + new_y);
		i++;
		}
		fdf->cor = fdf->cor->next;
	}
}
