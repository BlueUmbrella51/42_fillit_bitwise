#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lravier <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 08:51:33 by lravier       #+#    #+#                  #
#    Updated: 2019/04/25 12:42:57 by jdunnink      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC =	tetrominos_validation.c	\
		tetrominos_setup.c		\
		tetrominos_utility.c	\
		fillit_utility.c		\
		ft_error.c				\
		read_input.c			\
		main.c					\
		print_solution.c		\
		toggle_bit.c			\
		create_field.c			\
		print_part_field.c		\
		print_field.c			\
		add_bits.c				\
		move_bit.c				\
		move_bits.c				\

OBJ = $(SRC:.c=.o)
SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = -I includes/ -I libft/includes/
cc = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = -L libft/ -lft

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/ fclean && make -C libft
	$(CC) -o fillit $(CFLAGS) $(OBJS) $(HEADER) $(LIB)

$(OBJS): $(SRCS)
	/bin/mkdir -p $(OBJDIR)
	$(CC) -c $(CFLAGS) $(SRCS) $(HEADER)
	/bin/mv $(OBJ) $(OBJDIR)/

clean:
	/bin/rm -Rf $(OBJDIR)
	/bin/rm -Rf *~ *#
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all