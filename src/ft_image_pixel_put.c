/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:52:34 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/08 13:52:36 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_image_pixel_put(t_fdf *fdf, int x, int y, int rgb)
{
	int				bpp;
	int				sl;
	int				en;
	char			*image;
	unsigned int	tmp;

	image = mlx_get_data_addr(fdf->image, &bpp, &sl, &en);
	tmp = (mlx_get_color_value(fdf->mlx, rgb));
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
		ft_memcpy((void *)(image + y * WIN_X * (bpp / 8)) + x * (bpp / 8),
			(void *)&tmp, 4);
}
