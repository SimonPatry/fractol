# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sipatry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 14:25:01 by sipatry           #+#    #+#              #
#    Updated: 2019/03/26 15:18:14 by sipatry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

SRC = src/main.c \
	  src/mandelbrot.c \
	  src/tools.c \
	  src/colors.c \
	  src/julia.c	\
	  src/keys.c	\
	  src/keys2.c	\
	  src/hooks.c	\
	  src/thread.c	\
	  src/buddhabrot.c


INCLUDE = include/fractol.h

LIBFT = libft/libft.a

OBJS= $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

$(NAME): $(LIBFT) $(OBJS)
	@gcc $(FLAGS) -include $(INCLUDE) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)

$(LIBFT):
	@make -C libft/

%.o: %.c ../incude/fractol.h Makefile libft/makefile
	@gcc $(FLAGS) -include $(INCLUDE) -o $@ -c $<

all: $(NAME)

.PHONY: clean

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
