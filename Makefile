# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 23:25:21 by yait-oul          #+#    #+#              #
#    Updated: 2023/09/12 23:32:18 by yait-oul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ./parse/llist.c ./parse/llist2.c ./parse/parse.c ./parse/ft_atof.c ./parse/helper.c ./parse/helper2.c ./parse/helper3.c \
 ./src/vectors/vectors1.c ./src/vectors/vectors2.c ./src/vectors/vectors3.c ./src/vectors/vectors4.c \
 main.c closing.c ./src/vectors/vectors5.c ./parse/free.c \
 ./src/ray_tracer.c ./src/shadow.c ./src/sphere_intersect.c ./src/plane_intersect.c ./src/cylinder_intersect.c
 
FRAME = -framework OpenGL -framework Appkit -lmlx

INCLUDE = ./includes/vectors.h ./includes/structs.h

OBJ = $(SRC:.c=.o) 

%.o: %.c $(INCLUDE)
	cc -c $< -o $@ 

$(NAME): $(OBJ) 
	make -C ./libft
	cc $(OBJ) $(FRAME)  ./libft/libft.a -o $@

all: $(NAME) 

clean:
	make -C ./libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all