# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 16:34:15 by mabbadi           #+#    #+#              #
#    Updated: 2023/10/21 15:30:00 by mabbadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror -g3
MLX_ARGS = -lmlx -framework OpenGL -framework AppKit

# Liste des fichiers source
SOURCES := $(wildcard *.c) \
		   		$(wildcard libft/*.c)

# Liste des fichiers d'en-tête
HEADERS := fractol.h \
					$(wildcard libft/*.h)
# Génération de la liste des fichiers objets
OBJECTS := $(SOURCES:.c=.o)

# Règle pour la compilation des fichiers source en fichiers objets
%.o: %.c $(HEADERS)
	$(CC) $(FLAGS)  -Iincludes -c $< -o $@

# Règle pour la création de l'exécutable
$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) $(MLX_ARGS)

all: $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
