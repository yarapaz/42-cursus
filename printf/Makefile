NAME	= libftprintf.a

CC		= gcc
FLAGS	= -Wall -Wextra -Werror
LIB		= ar -rcs
INCLUDES	= ft_printf.h
SRCS	=	ft_printf.c src/ft_putchar.c src/ft_putstr.c src/ft_putnbr.c \
			src/ft_put_hexa_max.c src/ft_puthexa.c src/ft_puthexa_point.c \
			src/ft_unputnbr.c	
OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

.c.o:	$(SRCS)
		$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)
			

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)
			

clean:		
	rm -rf $(OBJS)
	
fclean:		clean
			rm -rf $(NAME) a.out

re:			fclean all


.PHONY:		all clean fclean re 