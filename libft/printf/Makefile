CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar rcs
OBJ = $(SRC:.c=.o)

SRC = ft_printf.c \
	ft_di_print.c \
	ft_cs_print.c \
	ft_cases.c \
	ft_u_print.c \
	ft_hex_print.c \
	ft_p_print.c \

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

test: $(NAME)
	cc -Wall -Wextra -Werror remmain.c $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re