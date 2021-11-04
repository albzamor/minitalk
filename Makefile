NAME_CLIENT = client
NAME_SERVER = server
LIBFT_NAME = libft.a
SRCS =  ./srcs/server.c \
		./srcs/client.c \
		./srcs/utils.c \

LIBFT_DIR = ./libft/

UNAME :=$(shell uname -m)
ifeq ($(UNAME), arm64)
CC = arch -x86_64 cc
MAKE = arch -x86_64 make
else
CC = cc
endif

OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
%.o: %.c
	$(CC)  $(CFLAGS) -c $< -o $@

$(NAME_CLIENT): $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	$(CC) $(LIBFT_DIR)$(LIBFT_NAME) $(NAME_CLIENT) $(NAME_SERVER) $^

$(NAME_SERVER): $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	$(CC) $(LIBFT_DIR)$(LIBFT_NAME) $(NAME_CLIENT) $(NAME_SERVER) $^

all: $(NAME_CLIENT) $(NAME_SERVER)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER

re: clean all

.PHONY: all clean fclean re

# shell uname -m architecture
# cp $(MLX_DIR)libmlx.dylib need to cp to the root
# m1 rule to compile en m1: firstime copy manual libmlx.dylib
# $@ (target)
# $< (first prerequisite  =dependency)
# $? names all prerequisites that are newer than the target
#	 separated by spaces
# $^ filenames all prerequisites that are newer than the target
# 	separated by spaces
# CC = arch -x86_64 cc  arch -X86_64 to compile in M1 minilibx
# arch -x86_64 $(MAKE) -C $(MLX_DIR)