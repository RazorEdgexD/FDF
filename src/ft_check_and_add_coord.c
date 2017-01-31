/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:54:23 by aosobliv          #+#    #+#             */
/*   Updated: 2017/01/26 16:54:25 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_check_number_and_color(char *s)
{
	int i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '-')
			i++;
		if (!is_digit(s[i]))
		{
			if (s[i] == ',')
			{
				i++;
				while (s[i] != '\0')
				{
					if ((s[i] == 'A' || s[i] == 'B' || s[i] == 'C' ||
					s[i] == 'D' || s[i] == 'E' || s[i] == 'F' || s[i] == 'x'
					|| s[i] == 'a' || s[i] == 'b' || s[i] == 'c' || s[i] == 'd'
					|| s[i] == 'e' || s[i] == 'f' || s[i] == '0')
					|| is_digit(s[i]))
						i++;
					else
						ft_number_error();
				}
				break ;
			}
			else
				ft_number_error();
		}
	}
}

void		ft_len_plus_color_check(int fd, t_fdf *fdf)
{
	int		len_x;
	char	*line;
	char	**split;
	int		tmp_len_x;

	len_x = 0;
	fdf->len_y = 0;
	tmp_len_x = 0;
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, 32);
		while (split[len_x] != NULL)
		{
			ft_check_number_and_color(split[len_x]);
			len_x++;
			tmp_len_x++;
		}
		printf("len_x=%d tmp/len=%d\n", len_x, tmp_len_x / (fdf->len_y + 1));
		if (len_x != tmp_len_x / (fdf->len_y + 1))
			ft_line_len_error();
		fdf->len_x = len_x;
		len_x = 0;
		fdf->len_y++;

	}
}

void		ft_add_coord(int fd2, t_fdf *fdf)
{
	char	*line;

	fdf->tmp = (char***)malloc(sizeof(char**) * (fdf->len_y + 1));
	fdf->arr_i = (int***)malloc(sizeof(int**) * (fdf->len_y));
	while (get_next_line(fd2, &line) == 1)
	{

		fdf->tmp[fdf->i] = ft_strsplit(line, 32);
		fdf->arr_i[fdf->i] = (int**)malloc(sizeof(int*) * (fdf->len_x));
	/*		printf("%s", fdf->tmp[fdf->i][0]);
			printf(" %s", fdf->tmp[fdf->i][1]);
			printf(" %s", fdf->tmp[fdf->i][2]);
			printf(" %s", fdf->tmp[fdf->i][3]);
			printf(" %s", fdf->tmp[fdf->i][4]);
			printf(" %s", fdf->tmp[fdf->i][5]);
			printf(" %s", fdf->tmp[fdf->i][6]);
			printf(" %s", fdf->tmp[fdf->i][7]);
			printf(" %s", fdf->tmp[fdf->i][8]);
			printf(" %s\n", fdf->tmp[fdf->i][9]);
	*/	while(fdf->tmp[fdf->j] != NULL)
		{
			fdf->arr_i[fdf->i][fdf->j] = (int*)malloc(sizeof(int) * 4);
			fdf->arr_i[fdf->i][fdf->j][0] = ft_atoi(fdf->tmp[fdf->i][fdf->j]);
			printf("DD=%d dd=%d z=%d |\n", fdf->j, fdf->i, fdf->arr_i[fdf->i][fdf->j][0]);
			fdf->j++;
		}
		fdf->i++;
	//	printf("d=%d", fdf->i);
	}
	fdf->tmp[fdf->len_y + 1] = NULL;
//	fdf->point->next = NULL;
}

void		ft_check_and_add_coord(int fd1, int fd2, t_fdf fdf)
{
	fdf.i = 0;
	fdf.j = 0;
	ft_len_plus_color_check(fd1, &fdf);
	ft_add_coord(fd2, &fdf);

}
