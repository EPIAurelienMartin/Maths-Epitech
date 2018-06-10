##
## EPITECH PROJECT, 2017
## make
## File description:
## file
##

CC	=	gcc

RM	=	rm -f

NAME	=	101pong

SRCS	=	main.c		\
		my_str_isnum.c

OBJ	=	$(SRCS:.c=.o)

CFLAGS +=	-W -Wall -Wextra

CFLAGS +=	-I ./

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lm

all	:	$(NAME)

clean	:
	$(RM) $(OBJ)

fclean :	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY:	all clean fclean re
