/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:10:35 by aosobliv          #+#    #+#             */
/*   Updated: 2017/01/31 19:10:36 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_bonus_color(t_fdf *fdf)
{
	fdf->bonus[0] = 8388352;
	fdf->bonus_text[0] = "Green";
	fdf->bonus[1] = 16711935;
	fdf->bonus_text[1] = "Fuchsia";
	fdf->bonus[2] = 16766720;
	fdf->bonus_text[2] = "Yellow";
	fdf->bonus[3] = 12433259;
	fdf->bonus_text[3] = "Khaki";
	fdf->bonus[4] = 14524637;
	fdf->bonus_text[4] = "Plum";
	fdf->bonus[5] = 16777215;
	fdf->bonus_text[5] = "White";
}

void	ft_take_color(char *str, t_cor *cord)
{
	char	*tmp;

	if ((tmp = ft_strchr(str, 'x')))
	{
		tmp++;
		cord->color = ft_atoi_base(tmp, 16);
		cord->red = (cord->color >> 16);
		cord->green = (cord->color >> 8) - (cord->red << 8);
		cord->blue = (cord->color) - (cord->red << 16) - (cord->green << 8);
	}
	else
	{
		cord->red = 255;
		cord->green = 255;
		cord->blue = 255;
		cord->color = 16777215;
	}
}

int		ft_make_color(int r, int g, int b)
{
	if (r != 0 && b != 0 && g != 0)
		return ((r << 16) + (g << 8) + b);
	return (16777215);
}
