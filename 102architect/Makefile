##
## EPITECH PROJECT, 2017
## maths
## File description:
## math
##

NAME	= 102architect

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c \
	  ./src/my_str_isnum.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
