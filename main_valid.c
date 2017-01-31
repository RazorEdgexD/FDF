/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:39:46 by aosobliv          #+#    #+#             */
/*   Updated: 2017/01/19 18:39:48 by aosobliv         ###   ########.fr       */
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
	//	fdf.mlx = mlx_init();
		ft_check_and_add_coord(fd1, fd2, fdf);
		close(fd1);
		close(fd2);
	}
	else
		ft_arguments_error();
	return (0);
}
