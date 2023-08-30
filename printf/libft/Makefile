NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIB = ar -rcs
INCLUDES = libft.h
SRCS_MAIN = ft_calloc.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putnbr.c		
OBJS_MAIN = $(SRCS_MAIN:.c=.o)
RM = /bin/rm -f

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $?

$(NAME): $(OBJS_MAIN) $(INCLUDES)
		$(LIB) $(NAME) $(OBJS_MAIN)

clean:
	$(RM) $(OBJS_MAIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
