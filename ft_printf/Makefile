NAME = libftprintf.a
SRC = ft_printf.c read_info.c print_cps.c print_diux.c utils1.c utils2.c
LIBFT = libft
LIBFT.A = libft.a
RM = rm -rf
LIB = ar rc
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT.A) $@
	$(LIB) $@ $^

clean:
	$(RM) $(OBJS) *.gch
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all
