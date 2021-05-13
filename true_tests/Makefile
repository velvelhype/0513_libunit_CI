NAME=true_function_test
CC=gcc
CFLAGS=-I$(FRAMEWORK_DIR) -Wall -Werror -Wextra
FRAMEWORK_DIR=../framework
LIBUNIT=$(FRAMEWORK_DIR)/libunit.a
SRCS=\
main.c \
true_function/00_launcher.c \
true_function/01_true_ok.c \
true_function/02_true_ko.c \
true_function/03_true_segv.c \
true_function/04_true_bus_err.c \
true_function/05_true_timeout.c \
true_function/06_true_sigfpe.c \
true_function/07_true_sigabrt.c \

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
