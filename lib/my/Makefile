##
## EPITECH PROJECT, 2021
## Pool day 10
## File description:
## Makefile
##

SRC = *.c

SRC_FLAGS = print_flags_func/*.c

OBJ = $(SRC:.c=.o)

OBJ_FLAGS = print_flags_func.o	\
			print_flags_func2.o	\
			print_flags_func3.o	\
			print_flags_func4.o	\
			print_flags_func5.o	\
			print_flags_func6.o	\
			print_flags_func7.o	\
			print_flags_func8.o	\
			print_flags_func9.o	\
			print_flags_func10.o

NAME_LIB = libmy.a

NAME_MY = my.h

all:	copy_lib	copy_my	\
	clean

copy_lib:
	gcc -c $(SRC) $(SRC_FLAGS) -I../../include
	ar rc $(NAME_LIB) $(OBJ) $(OBJ_FLAGS)
	cp $(NAME_LIB) ..

copy_my:
	cp $(NAME_MY) ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME_LIB)
	rm -f ../$(NAME_LIB)