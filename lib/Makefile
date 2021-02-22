NAME = cslib.a

all: $(NAME)

RM = rm -f
CC = clang
CFLAGS = -Wall -Wextra -g
SRCS = strncmp.c hexvalue.c isalnum.c  isalpha.c  isdigit.c  islower.c  isoctal.c  isprint.c  isspace.c  isupper.c  isxdigit.c main.c     puts.c     strlen.c   tolower.c  toupper.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar -r $@ $^
	ranlib $@

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@  $<

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: clean all