# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bramjr <bramjr@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/17 18:32:04 by bramjr        #+#    #+#                  #
#    Updated: 2021/10/04 15:03:49 by bprovoos      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Change this data depends on your files you have

NAME	= libft.a
HEADER	= libft.h
SRCS 	= ft_strlen.o $\
		  ft_itoa_long_base.o $\
		  ft_itoa_unsignedlong_base.o $\
		  ft_putchar_fd.o $\
		  ft_putstr_fd.o $\
		  ft_strchr.o $\
		  ft_strtoupper.o $\
		  ft_toupper.o $\
		  ft_islower.o $\

# The code below does not need to be changed

CFLAGS	= -Wall -Wextra -Werror
RM 		= rm -rf

OBJ = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)


%.o : %.c $(HEADER)
	$(CC) -c $(FLAGS) -o $@ $<


clean:
	${RM} $(OBJ)


fclean: clean
	${RM} $(NAME)


re: fclean all


.PHONY: all clean bonus fclean re
