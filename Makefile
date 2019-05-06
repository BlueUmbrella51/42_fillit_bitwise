#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lravier <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 08:51:33 by lravier       #+#    #+#                  #
#    Updated: 2019/05/06 10:16:52 by jdunnink      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC =	read_input.c			\
		main.c					\
		read_tetro.c			\
		solver.c				\
		tetro_translate.c		\
		validate_tetro.c 		\
		checker.c				\
		list_sort.c				\
		print_solution.c		\
		toggle_tetro.c			\
		add_tetro.c				\
		find_permutations.c 	\
		ft_error.c 				\
		itocoor.c				\
		count_ones.c 			\
		index_conversion.c 		\
		sizer.c					\
		solve_map.c				\
		solve_pos.c				\
		list_len.c				\
		available_space.c		\

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
