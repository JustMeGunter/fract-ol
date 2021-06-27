# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 02:44:28 by acrucesp          #+#    #+#              #
#    Updated: 2021/06/27 02:48:33 by acrucesp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR				=	src/
SRC					=	

MAIN				=

OBJ_DIR				=	obj/
OBJ					= 	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

INC_DIR				=	inc/
HEADER				= 	inc/.h

NAME				= 	.a

CC					=	gcc	

RM					= 	rm -f

CFLAGS				= 	-Wall -Wextra -Werror -g 

all:				$(NAME)


$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I Libft/inc/ -c $< -o $@ 

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME):			Libft/libft.a $(OBJC) 
	ar rcs $(NAME) $(OBJC) Libft/obj/*.o 

test:				re
	$(CC) $(CFLAGS) -I Libft/inc/ -I inc/ -o $@ $(TMAIN) $(NAME)

Libft/libft.a:
	$(MAKE) -C Libft

.PHONY:				all clean fclean re bonus			

clean:
	$(RM) -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) -C Libft clean

fclean:				clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean
	$(RM) test

re:					fclean all

