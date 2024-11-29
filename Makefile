CC = cc
CFLAG = -Wall -Wextra -Werror
NAME = libftprintf.a
HEAD = ft_printf.h
SRCS = srcs/ft_printf.c srcs/ft_putc.c srcs/ft_putnb.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rsc $@ $^

.c.o :
	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@

clean : 
	rm -rf srcs/*.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean
