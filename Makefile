NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c 

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=1200

HEADER = get_next_line.h 

AR = ar rcs

RM = rm -f 

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re