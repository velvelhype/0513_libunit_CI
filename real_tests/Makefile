NAME=real_unit_test
CC=gcc
CFLAGS=-I$(FRAMEWORK_DIR) -Ilibft -Wall -Werror -Wextra
FRAMEWORK_DIR=../framework
LIBUNIT=$(FRAMEWORK_DIR)/libunit.a
SRCS=\
main.c \
libft/ft_strlen.c \
libft/ft_atoi.c \
ft_strlen/00_launcher.c \
ft_strlen/01_basic_test.c \
ft_strlen/02_long_string.c \
ft_strlen/03_one_letter.c \
ft_strlen/04_zero_length.c \
ft_strlen/05_non_printable.c \
ft_atoi/00_launcher.c \
ft_atoi/01_basic_test.c \
ft_atoi/02_minus_test.c \
ft_atoi/03_plus_test.c \
ft_atoi/04_space_test.c \
ft_atoi/05_space_minus_test.c \
ft_atoi/06_space_plus_test.c \
ft_atoi/07_plus_minus_test.c \
ft_atoi/08_void_string.c \
ft_atoi/09_floating_point_number.c \
ft_atoi/10_non_digit_tail.c \
ft_atoi/11_int_max.c \
ft_atoi/12_int_mini.c \
ft_atoi/13_overflow.c \
ft_atoi/14_underflow.c \
ft_atoi/15_zero.c \
ft_atoi/16_000_head.c \

OBJS=$(SRCS:.c=.o)

.PHONY: test all clean fclean re

test: $(NAME)
	$(RM) report.log
	./$(NAME) 2> /dev/null

all: $(NAME)

$(NAME): $(LIBUNIT) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBUNIT)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(LIBUNIT):
	make -C $(FRAMEWORK_DIR)

