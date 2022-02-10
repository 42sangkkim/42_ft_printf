NAME := libftprintf.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror -c -o

AR := ar
ARFLAGS := -crv

RM := rm
RMFLAGS := -f

C_SRCS := ft_printf.c

M_DIR := ./dir_mandatory
M_SRCS := \
	$(M_DIR)/get_format.c \
	$(M_DIR)/check_format.c \
	$(M_DIR)/make_buffer.c \
	$(M_DIR)/make_buffer2.c

TARGET_OBJS := $(C_SRCS:.c=.o) $(M_SRCS:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) $@ $^

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