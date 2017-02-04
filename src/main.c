/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:39:46 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/04 02:07:37 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	t_fdf	fdf;

	if (argc == 2)
	{
		if ((fd1 = open(argv[1], O_RDONLY)) < 1)
			ft_open_file_error();
		if ((fd2 = open(argv[1], O_RDONLY)) < 1)
			ft_open_file_error();
		fdf.i = 0;
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, WIN_X, WIN_Y, "FDF by Razor");
		fdf.center_x = WIN_X / 2;
		fdf.center_y = WIN_Y / 4;
		ft_check_and_add_coord(fd1, fd2, &fdf);
		ft_draw(&fdf);
		printf("LEN_X=%d | LEN_Y=%d\n", fdf.len_x, fdf.len_y);
		close(fd1);
		close(fd2);
		mlx_loop(fdf.mlx);
	}
	else
		ft_arguments_error();
	return (0);
}
