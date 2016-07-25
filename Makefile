#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 00:10:34 by gmevelec          #+#    #+#              #
#    Updated: 2015/04/29 00:13:18 by gmevelec         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_p

SERVEUR = SRC_serveur/serveur.c \
		SRC_serveur/ft_ls.c \
		SRC_serveur/ft_cd.c \
		SRC_serveur/put_get.c \

CLIENT = SRC_client/client.c\
		SRC_client/ft_aff.c \
		SRC_client/put_get.c \

COMMUN = SRC_commun/file_transfert.c \
		SRC_commun/paquet.c \
		SRC_commun/ft_error.c \

OBJ_COMMUN = $(COMMUN:.c=.o)

OBJ_S = $(SERVEUR:.c=.o)

OBJ_C = $(CLIENT:.c=.o)

INC = -I./libft
FLAGS = -Wall -Werror -Wextra -g
LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_C) $(OBJ_S) $(OBJ_COMMUN)
	make -C ./libft
	gcc $(FLAGS) -o serveur $(OBJ_S) $(OBJ_COMMUN) $(LIB)
	gcc $(FLAGS) -o client $(OBJ_C) $(OBJ_COMMUN) $(LIB)

%.o: %.c
	gcc $(FLAGS) $(INC) -c $< -o $@

serveur:
	make -C ./libft
	gcc $(FLAGS) $(INC) -o serveur $(OBJ_S) $(OBJ_COMMUN) $(LIB)

client:
	make -C ./libft
	gcc $(FLAGS) $(INC) -o client $(OBJ_C) $(OBJ_COMMUN) $(LIB)

clean:
	make -C ./libft clean
	rm -f $(OBJ_S) $(OBJ_C) $(OBJ_COMMUN)

fclean: clean
	make -C ./libft fclean
	rm -f serveur
	rm -f client

re: fclean all
