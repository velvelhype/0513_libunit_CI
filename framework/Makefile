NAME=libunit.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra -I$(LIBFT_DIR)
BONUS=0
LIBFT_DIR=libft
LIBFT=$(LIBFT_DIR)/libft.a

ifeq ($(BONUS), 0)
LAUNCH_SRC=launch_tests.c
else
LAUNCH_SRC=launch_tests_bonus.c report.c
endif

SRCS=\
load_test.c \
test_list.c \
libft/ft_isdigit.c \
libft/ft_itoa.c \
libft/ft_strdup.c \
libft/ft_strlen.c \
libft/ft_putchar_fd.c \
libft/ft_putendl_fd.c \
libft/ft_putnbr_fd.c \
libft/ft_memcpy.c \
libft/ft_putstr_fd.c \
$(LAUNCH_SRC)

OBJS=$(SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

clean:
	$(RM) $(OBJS)
	$(RM) launch_tests_bonus.o report.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: fclean
	make BONUS=1 all
