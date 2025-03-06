# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-karm <mel-karm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:46:19 by mel-karm          #+#    #+#              #
#    Updated: 2023/10/17 15:20:17 by mel-karm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS= srcs/main.c srcs/utils2.c srcs/draw_rays5.c srcs/collision2.c srcs/others.c srcs/collision.c srcs/draw_map.c srcs/draw_rays.c   srcs/draw_rays2.c srcs/draw_rays3.c srcs/draw_rays4.c srcs/parsing.c srcs/libft.c srcs/parsing2.c srcs/parsing3.c srcs/parsing4.c srcs/parsing5.c srcs/parsing6.c  srcs/parsing7.c srcs/movements.c srcs/utils.c srcs/ft_split.c   srcs/get_next_line.c srcs/get_next_line_utils.c
OBJS=$(SRCS:.c=.o)
NAME=cub3D

CFLAGS=-Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
	cd srcs
	cc $(OBJS)  -g  -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c include/cub3d.h
	cd srcs 
	cc  $(CFLAGS)  -g -Imlx -c   $< -o $@

clean	:
	cd srcs 
	rm -rf $(OBJS) && rm -rf ft_split.o ft_strlen.o ft_substr.o
	

fclean 	: 	clean
	rm -rf $(NAME)

re		: 	fclean all

.PHONY	: 	fclean all clean re