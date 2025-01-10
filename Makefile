# NAMES
NAME_SERVER = server
NAME_CLIENT = client

#flags to compile
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

#DIR
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
INCLUDE_DIR = include

SRCS_SERVER = $(SRC_DIR)/server.c
SRCS_CLIENT = $(SRC_DIR)/client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

#RULES
all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

#compile server
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

#complie client
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

#compile lib
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a .

#clean objects
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) clean

#clean everthing
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) libft.a
	$(MAKE) -C $(LIBFT_DIR) fclean

#re-compile
re: fclean all

#phony
.PHONY: all clean fclean re