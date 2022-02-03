NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

AR = ar
ARFLAGS = -crv

RM = rm
RMFLAGS = -f

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

M_DIR = dir_man
M_SRCS =	dir_mandatory/print_fstring.c\
			dir_mandatory/skip_fstring.c\

%.o:%.c
	$(CC) $(CFLAGS) $^

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

.Phony : all clean fclean re

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all