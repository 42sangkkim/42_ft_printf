NAME := libftprintf.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror -c

AR := ar
ARFLAGS := -crv

RM := rm
RMFLAGS := -f

C_SRCS := ft_printf.c

M_DIR := dir_mandatory
M_SRCS := \
	dir_mandatory/print_fstring.c \
	dir_mandatory/skip_fstring.c \
	dir_mandatory/put_char.c \
	dir_mandatory/put_str.c \
	dir_mandatory/put_addr.c \
	dir_mandatory/put_deci.c \
	dir_mandatory/put_hex.c \
	dir_mandatory/make_digit.c

TARGET_OBJS := $(C_SRCS:.c=.o) $(M_SRCS:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $^

$(NAME) : $(TARGET_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(TARGET_OBJS)

.Phony : all clean fclean re

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(C_SRCS:.c=.o) $(M_SRCS:.c=.o)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

print :
	echo $(TARGET_OBJS)

re : fclean all