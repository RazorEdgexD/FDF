/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:20:47 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/09 16:20:49 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_str(t_fdf *fdf, char *str)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, fdf->text_y, 0xFFFFFF, str);
	fdf->text_y += 20;
}

void	ft_print_info(t_fdf *fdf)
{
	fdf->text_y = 20;
	if (fdf->l == 37.5 * RAD && fdf->b == -40.19 * RAD && fdf->y == 0)
		ft_print_str(fdf, "Type of projection = iso");
	else
		ft_print_str(fdf, "Type of projection = parallel");
	ft_print_str(fdf, ft_strjoin("Zoom = x", ft_itoa(fdf->scalall * 10)));
	ft_print_str(fdf, ft_strjoin("Alpha = ", ft_itoa(fdf->l / RAD)));
	ft_print_str(fdf, ft_strjoin("Beta = ", ft_itoa(fdf->b / RAD)));
	ft_print_str(fdf, ft_strjoin(ft_strjoin("ZoomHeight = x", ft_itoa(fdf->scalz
	/ 1)), ft_strjoin(".", ft_itoa((int)(fdf->scalz * 10) % 10))));
	ft_print_str(fdf, ft_strjoin("ShiftX = ", ft_itoa(fdf->deltax)));
	ft_print_str(fdf, ft_strjoin("ShiftY = ", ft_itoa(fdf->deltay)));
	ft_print_str(fdf, "~~~~~~~Key~~~~~~~");
	ft_print_str(fdf, " '1','3'			- change angle Alpha");
	ft_print_str(fdf, " '7','9'			- change angle");
	ft_print_str(fdf, " '2','4','6','8'	- move");
	ft_print_str(fdf, " '*'				- change color");
	ft_print_str(fdf, " '+','-'			- Zoom");
	ft_print_str(fdf, " 'PUp','PUd'		- ZoomHeight");
	ft_print_str(fdf, " '5'				- First Params");
}
