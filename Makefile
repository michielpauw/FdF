# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpauw <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 10:22:09 by mpauw             #+#    #+#              #
#    Updated: 2017/12/06 17:42:59 by mpauw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror 
INCLUDES = fdf.h
SRCS = fdf.c \
	  edit_image.c \
	  get_data.c \
	  window_control.c \
	  manipulate_data.c \
	  get_matrices.c
OBJ = $(SRCS:%.c=%.o)
LFTDIR = libft/
LMLXDIR = minilibx_macos/ 
#LMLXDIR = mlx_macbook/ 
LIBFT = libft.a
LIBMLX = libmlx.a
FT = ft
MLX = mlx
MAKE = make
FRAMEWORK = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(OBJ) $(LFTDIR)$(LIBFT) $(LMLXDIR)$(LIBMLX) 
	-@gcc $(FLAGS) -o $(NAME) -g $(OBJ) -I$(LFTDIR) -L$(LFTDIR) -l$(FT) \
		-L$(LMLXDIR) -l$(MLX) $(FRAMEWORK)
	-@echo "FdF Ready"

%.o: %.c $(INCLUDES)
	-@gcc $(FLAGS) -I$(LFTDIR) -I$(LMLXDIR) -c $(SRCS)

$(LFTDIR)$(LIBFT):
	$(MAKE) -C $(LFTDIR) $(LIBFT)

$(LMLXDIR)$(LIBMLX):
	$(MAKE) -C $(LMLXDIR) $(LIBMLX)

clean:
	-@/bin/rm -f $(OBJ)
	-@$(MAKE) -C $(LFTDIR) clean
	-@$(MAKE) -C $(LMLXDIR) clean

fclean: clean
	-@/bin/rm -f $(NAME)
	-@$(MAKE) -C $(LFTDIR) fclean

re: fclean all
