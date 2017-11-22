/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:39:43 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/09 16:39:45 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color(t_fdf *fdf)
{
	if (fdf->k != 0)
		fdf->k--;
	else
		fdf->k = 5;
}

void	start_coord(t_fdf *fdf)
{
	fdf->l = 37.5 * RAD;
	fdf->b = -40.19 * RAD;
	fdf->deltay = 0;
	fdf->deltax = 0;
	fdf->scalz = fdf->old_scalz;
	fdf->scalall = fdf->old_scalall;
}

void	addition_key(int keycode, t_fdf *fdf)
{
	if (keycode == 87)
		start_coord(fdf);
	if (keycode == 83)
		fdf->l += 1 * RAD;
	if (keycode == 85)
		fdf->l -= 1 * RAD;
	if (keycode == 89)
		fdf->b += 1 * RAD;
	if (keycode == 92)
		fdf->b -= 1 * RAD;
	if (keycode == 84)
		fdf->deltay += 10;
	if (keycode == 91)
		fdf->deltay -= 10;
	if (keycode == 86)
		fdf->deltax -= 10;
	if (keycode == 88)
		fdf->deltax += 10;
	if (keycode == 67)
		change_color(fdf);
}

int		take_key(int keycode, t_fdf *fdf)
{
	addition_key(keycode, fdf);
	if (keycode == 53)
		exit(777);
	if (keycode == 116)
		fdf->scalz += 0.1;
	if (keycode == 121)
		fdf->scalz -= 0.1;
	if (keycode == 78)
		if (fdf->scalall >= 0.2)
			fdf->scalall -= 0.1;
	if (keycode == 69)
		fdf->scalall += 0.1;
	mlx_destroy_image(fdf->mlx, fdf->image);
	fdf->image = mlx_new_image(fdf->mlx, WIN_X, WIN_Y);
	fdf->i = 0;
	fdf->j = 0;
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	ft_print_info(fdf);
	return (0);
}

int		ft_loop_hook(t_fdf *fdf)
{
	fdf->image = mlx_new_image(fdf->mlx, WIN_X, WIN_Y);
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	mlx_key_hook(fdf->win, take_key, fdf);
	ft_print_info(fdf);
	return (0);
}
