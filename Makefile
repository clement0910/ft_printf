
C = gcc

NAME = libftprintf.a

SRCS = srcs/ft_printf.c \
		srcs/ft_printf_flags.c \
		srcs/ft_printf_aux.c \
		srcs/ft_printf_conversion.c \
		srcs/ft_printf_conversion2.c \
		srcs/ft_printf_convertutils.c \

FLAGS = -ggdb -Wall -Werror -Wextra

OBJ = $(SRCS:.c=.o)

LIB = libft/libft.a

all: $(NAME)

$(LIB):
	make -C libft/

$(NAME): $(LIB) $(OBJ)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) -I includes/ -o $@ -c $< $(FLAGS)

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB)

re: fclean all