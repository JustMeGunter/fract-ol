# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 02:44:28 by acrucesp          #+#    #+#              #
#    Updated: 2021/09/09 21:59:55 by acrucesp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG 				=

SRC_DIR				=	src/
SRC					=	main.c mandelbrot_set.c get_params.c get_colors.c\
						get_controls.c parse_args.c julia_set.c my_mlx_pixel_put.c\
						bonus_a.c bonus_b.c						 

OBJ_DIR				=	obj/
OBJ					= 	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

INC_DIR				=	inc/
HEADER				= 	inc/.h

NAME				=	fractol 

CC					=	gcc	

RM					= 	rm -f

SANITIZE			=	-fsanitize=address

OPTIMIZED			=	-O3	

CFLAGS				= 	-Wall -Wextra -Werror $(OPTIMIZED) $(DEBUG)

UNAME_S := $(shell uname -s)

all:				$(NAME)

bonus:				all

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
ifeq ($(UNAME_S), Linux)
	$(CC) $(CFLAGS) -Imlx_mac -I $(INC_DIR) -I Libft/inc/ -c $< -o $@ 
else
	$(CC) $(CFLAGS) -Imlx_linux -I $(INC_DIR) -I Libft/inc/ -c $< -o $@ 
endif

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME):	libmlx.a Libft/libft.a $(OBJ) 
ifeq ($(UNAME_S), Linux)
	$(CC) $(CFLAGS) -I Libft/inc/ -I inc/ -Imlx_linux -lXext -lX11 -lm -lz\
		$(MAIN) $(OBJ) Libft/libft.a libmlx.a -o $@ 
else
	$(CC) $(CFLAGS) -I Libft/inc/ -I inc/ -Imlx_mac -framework OpenGL -framework AppKit\
		$(OBJ) Libft/libft.a libmlx.a -o $@ 
endif

Libft/libft.a: 		 
	$(MAKE) -C Libft

libmlx.a:
ifeq ($(UNAME_S), Linux)
	$(MAKE) -C mlx_linux
	cp mlx_linux/libmlx.a ./
else
	$(MAKE) -C mlx_mac 
	cp mlx_mac/libmlx.a ./
endif

.PHONY:				all clean fclean re bonus

clean:
	$(RM) -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) -C Libft clean
	$(RM) -rf libmlx.a
ifeq ($(UNAME_S), Linux)
	$(MAKE) -C mlx_linux clean 
else
	$(MAKE) -C mlx_mac clean 
endif

fclean:				clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean

re:					fclean all

