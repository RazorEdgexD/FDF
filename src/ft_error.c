/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:23:26 by aosobliv          #+#    #+#             */
/*   Updated: 2017/01/26 16:23:29 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_arguments_error(void)
{
	ft_putendl("Too few/many arguments...");
	exit(1);
}

void	ft_open_file_error(void)
{
	ft_putendl("Cannot open file...");
	exit(2);
}

void	ft_malloc_error(void)
{
	ft_putendl("Cannot malloc RAM...");
	exit(3);
}

void	ft_line_len_error(void)
{
	ft_putendl("Wrong line elements size...");
	exit(4);
}

void	ft_number_error(void)
{
	ft_putendl("Not Number or Wrong Color...");
	exit(5);
}
