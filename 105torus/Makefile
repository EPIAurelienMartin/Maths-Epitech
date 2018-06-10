##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	= 105torus

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c 

OBJS	= $(SRCS:.c=.o)

LIB = -L ./lib/ -lmy -lm

CFLAGS = -I ./include/

CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 make -C ./lib/my/
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./lib/my/

re: fclean all

.PHONY: all clean fclean re
