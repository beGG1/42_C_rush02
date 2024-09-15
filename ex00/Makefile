TARGET=rush-02
SRC=main.c	\
	file_ops.c	\
	dict_parser.c	\
	convertion.c	\
	output.c	\
	custom_hashmap.c

DEPS=custom_hashmap.h
CC=cc
CFLAGS=-Wall -Werror -Wextra

# By default make all the programs
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

default: all

clean:
	find . -type f -executable -print -exec rm {} \;

fclean:
	find . -type f -executable -print -exec rm {} \;

.PHONY: all clean