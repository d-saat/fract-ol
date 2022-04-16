# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaat <dsaat@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/16 16:43:18 by dsaat         #+#    #+#                  #
#    Updated: 2022/04/09 15:57:12 by dsaat         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[0;33m
PURPLE = \033[0;35m
GREEN = \033[0;32m
RESET = \033[0m

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
	help.c\
	render.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(SRCS:.c=.o)
LIBS = -L ./minilibx -lmlx -L ./Libft -l ft
CFLAGS = -Wall -Werror -Wextra
FRAMEWORK = -framework OpenGl -framework AppKit
INCLUDES = -I ./minilibx -I ./Libft -I ./includes

all: $(NAME)
	@make graphic

$(NAME): $(OBJS) minilibx/libmlx.a libft/libft.a
	@echo "$(PURPLE) compiling fractol$(RESET)"
	$(CC) $(FLAGS) $(FRAMEWORK) $(INCLUDES) $(LIBS) $(SRCS) -o $(NAME)

%.o: %.c
	$(CC) -c $(INCLUDES) $< -o $@

minilibx/libmlx.a:
	@echo "$(YELLOW) compiling minilibx$(RESET)"
	$(MAKE) -C ./minilibx

libft/libft.a:
	@echo "$(YELLOW) compiling libft$(RESET)"
	$(MAKE) -C ./libft

graphic:
	@echo "$(GREEN)	    __________  ___   ________________  __ "
	@echo "$(GREEN)	   / ____/ __ \/   | / ____/_  __/ __ \/ / "
	@echo "$(GREEN)	  / /_  / /_/ / /| |/ /     / / / / / / /  "
	@echo "$(GREEN)	 / __/ / _, _/ ___ / /___  / / / /_/ / /___"
	@echo "$(GREEN)	/_/   /_/ |_/_/  |_\____/ /_/  \____/_____/$(RESET)\n"

clean:
	$(MAKE) -C ./minilibx clean
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all