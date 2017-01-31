/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:52:20 by aosobliv          #+#    #+#             */
/*   Updated: 2017/01/18 17:52:59 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include <stdio.h>
#define y_0 480
#define x_0 640
int		main(void)
{
	void *mlx;
	void *win;
	int		x;
	int		y;
	int		x_new = 0;
	int		y_new = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1280, 960, "A4KO 1488");
	y = 280;         // KVADRAT 4 4ETVERT
	while (y < 480)
	{
		x = 640;
		while (x < 840)
		{
			mlx_pixel_put(mlx, win, x, y, 0x7FFF00);
			x += 1;
		}
		y += 1;
	}

/*	y = 280;         // KVADRAT 4 4ETVERT NA 45* VMESTE
	while (y < 480)
	{
		x = 640;
		while (x < 840)
		{
			x_new = ((x - x_0) * sin(0.786)) - ((y - y_0) * sin(0.786));
			y_new = ((x - x_0) * sin(0.786)) + ((y - y_0) * cos(0.786));
			x_new = x_new + x_0;
			y_new = y_new + y_0;
		//	printf("%d=%d\n", x_new, y_new);
			mlx_pixel_put(mlx, win, x_new, y_new, 0x0000FF);
			x += 1;
		}
		y += 1;
	}
*/
	y = 280;         // KVADRAT 4 4ETVERT NA 90* VMESTE +++ EWE POVOROT NA PRAVO
	while (y < 480)
	{
		x = 640;
		while (x < 840)
		{
			x_new = ((x - x_0) * cos(-3 * 0.786)) + 5 * (sin(-3 * 0.786));
			y_new = ((x - x_0) * sin(0.786) * cos(0.786)) + ((y - y_0) * cos(0.786)) -  5 * ((sin(0.786) * cos (-3 * 0.786)));
			x_new = x_new + x_0;
			y_new = y_new + y_0;
		//	printf("%d=%d\n", x_new, y_new);
			mlx_pixel_put(mlx, win, x_new, y_new, 0xFF3333);
			x += 1;
		}
		y += 1;
	}

/*	y = 280;         // KVADRAT 4 4ETVERT NA 135* VMESTE
	while (y < 480)
	{
		x = 640;
		while (x < 840)
		{
			x_new = ((x - x_0) * sin(4 * 0.786)) - ((y - y_0) * sin(4 * 0.786));
			y_new = ((x - x_0) * sin(4 * 0.786)) + ((y - y_0) * cos(4 * 0.786));
			x_new = x_new + x_0;
			y_new = y_new + y_0;
		//	printf("%d=%d\n", x_new, y_new);
			mlx_pixel_put(mlx, win, x_new, y_new, 0xFFFF66);
			x += 1;
		}
		y += 1;
	}

	y = 280;         // KVADRAT 4 4ETVERT NA 135* VMESTE
	while (y < 480)
	{
		x = 640;
		while (x < 840)
		{
			printf("%d=%d\n", x, y);
			x_new = ((x - x_0) * sin(5 * 0.786)) - ((y - y_0) * sin(5 * 0.786));
			y_new = ((x - x_0) * sin(5 * 0.786)) + ((y - y_0) * cos(5 * 0.786));
			x_new = x_new + x_0;
			y_new = y_new + y_0;
		//	printf("%d=%d\n", x_new, y_new);
			mlx_pixel_put(mlx, win, x_new, y_new, 0xFF00FF);
			x += 1;
		}
		y += 1;
	}

	y = 280;         // KVADRAT 4 4ETVERT NA 135* VMESTE
	while (y < 480)
	{
		x = 640;
		while (x < 840)
		{
			x_new = ((x - x_0) * sin(6 * 0.786)) - ((y - y_0) * sin(6 * 0.786));
			y_new = ((x - x_0) * sin(6 * 0.786)) + ((y - y_0) * cos(6 * 0.786));
			x_new = x_new + x_0;
			y_new = y_new + y_0;
		//	printf("%d=%d\n", x_new, y_new);
			mlx_pixel_put(mlx, win, x_new, y_new, 0xFFFFFF);
			x += 1;
		}
		y += 1;
	} */
	mlx_loop(mlx);
	//return (0);
}
