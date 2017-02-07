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
