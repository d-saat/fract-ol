# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaat <dsaat@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/16 16:43:18 by dsaat         #+#    #+#                  #
#    Updated: 2022/04/08 12:13:37 by dsaat         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS_DIR = ./sources/
SRCS_LIST = \
	main.c\
	draw_fractol.c\
	init_fractol.c\
	key_events.c\
	mouse_events.c\
	pixel_color.c\
	utils.c\
	help.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(SRCS:.c=.o)
LIBS = -L ./minilibx -lmlx -L ./Libft -l ft
CFLAGS = -Wall -Werror -Wextra
FRAMEWORK = -framework OpenGl -framework AppKit
INCLUDES = -I ./minilibx -I ./Libft -I ./includes

all: $(NAME)

$(NAME):
	$(MAKE) -C ./minilibx
	$(MAKE) -C ./Libft
	$(CC) $(FLAGS) $(FRAMEWORK) $(INCLUDES) $(LIBS) $(SRCS) -o $(NAME)

clean:
	$(MAKE) -C ./minilibx clean
	$(MAKE) -C ./Libft clean
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all