/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brezen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:16:37 by aosobliv          #+#    #+#             */
/*   Updated: 2017/01/31 21:16:38 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_brezen(int x0, int y0, int x1, int y1, int color, t_fdf *fdf)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;

//	printf("%d|%d   =   %d|%d\n", x0, y0, x1, y1);
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = x1 >= x0 ? 1 : -1;
	sy = y1 >= y0 ? 1 : -1;
	if (dy <= dx)
	{
		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;
		mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, color);
	for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
	{
		if (d >0)
		{
			d += d2;
			y += sy;
		}
		else
			d += d1;
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
		}
 	}
 	else
 	{
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;
		mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, color);
		for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
		{
			if (d > 0)
			{
				d += d2;
				x += sx;
			}
			else
				d += d1;
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
		}
 	}
}

void drawLine(t_draw *draw, t_fdf *fdf)
{
//    const int draw-deltaX = abs(x2 - x1);
//    const int deltaY = abs(y2 - y1);
//    const int signX = x1 < x2 ? 1 : -1;
//    const int signY = y1 < y2 ? 1 : -1;
//    int error = deltaX - deltaY;
//	const int error2 = error * 2;

    mlx_pixel_put(fdf->mlx, fdf->win, draw->x2, draw->y2, fdf->cor->color);
    while(draw->x1 != draw->x2 || draw->y1 != draw->y2)
   {
        mlx_pixel_put(fdf->mlx, fdf->win, draw->x2, draw->y2, fdf->cor->color);
        if(draw->error2 > -draw->deltaY)
        {
            draw->error -= draw->deltaY;
            draw->x1 += draw->signX;
        }
        if(draw->error2 < draw->deltaX)
        {
            draw->error += draw->deltaX;
            draw->y1 += draw->signY;
        }
    }
}
