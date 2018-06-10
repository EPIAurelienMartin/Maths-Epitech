##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

NAME	= 106bombyx

CC	= gcc

RM	= rm -f

SRCS	=	./src/main.c	\
		./src/help.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/

CFLAGS += -W -Wall -Wextra

LIB	= -L ./lib/ -lmy

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my/
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB)

clean:
	make clean -C ./lib/my/
	$(RM) $(OBJS)

fclean: clean
	$(RM) ./lib/libmy.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
