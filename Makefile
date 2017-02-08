# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 13:28:10 by aosobliv          #+#    #+#              #
#    Updated: 2017/02/08 18:17:51 by aosobliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

IDIR = includes/

VPATH = src:includes

FLAGS = -Wall -Wextra -Werror -I$(IDIR)

MLX = -lmlx -framework AppKit -framework OpenGl

SRCS = main.c										\
		ft_error.c									\
		ft_atoi_base.c								\
		ft_brezen.c									\
		ft_check_and_add_coord.c					\
		ft_color.c									\
		ft_draw.c									\
		ft_image_pixel_put.c						\
		ft_loop_hook.c								\

BINS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS) $(FLAGS) -L. libft/libft.a $(MLX)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
