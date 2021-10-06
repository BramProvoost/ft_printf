# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprovoos <bprovoos@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/22 10:33:38 by bprovoos      #+#    #+#                  #
#    Updated: 2021/10/01 14:43:32 by bprovoos      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Change this data depends on your files you have

NAME 			= libftprintf.a
HEADER 			= ft_printf.h
SRCS 			= src/ft_printf.o
LIBFT_PATH		= ./util/libft/
LIBFT_NAME		= libft.a
TEST_PATH		= test_ft_printf/
TEST_NAME		= main.c

# The code below does not need to be changed

CC 				= gcc
FLAGS			= -Wall -Werror -Wextra
RM 				= rm -rf
EXECUTABLE_NAME = test
OBJ 			= $(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJ)
	make -C ${LIBFT_PATH}
	cp ${LIBFT_PATH}${LIBFT_NAME} $(NAME)
	ar crs $(NAME) $(OBJ)


%.o: %.c $(HEADER)
	$(CC) -c $(FLAGS) -g -o $@ $<


clean:
	${RM} $(OBJ)
	make clean -C ${LIBFT_PATH}


fclean:
	${RM} $(OBJ)
	${RM} $(NAME)
	${RM} $(EXECUTABLE_NAME)
	${RM} $(EXECUTABLE_NAME).dSYM
	make fclean -C ${LIBFT_PATH}


re: fclean all
	make re -C ${LIBFT_PATH}


test: $(NAME)
	@# @echo "\033c"
	@$(CC) $(FLAGS) -g $(NAME) ${TEST_PATH}${TEST_NAME} -o $(EXECUTABLE_NAME)
	echo ----- run test -----
	./$(EXECUTABLE_NAME)


.PHONY: all clean fclean re
