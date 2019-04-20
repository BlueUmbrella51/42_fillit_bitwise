/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 08:38:03 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/20 14:46:17 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define SIZE 4

# include "get_next_line.h"
# include "../libft/includes/libft.h"
#include <stdio.h>                      // DONT FORGET TO REMOVE THIS INCLUDE

typedef struct s_tetro
{
    unsigned short tetro;                       // tetro
    int width;                          // total width of tetro
    int height;                         // total height of tetro
    char print;
}              t_tetro;

size_t  find_mapsize(size_t count);
int     check_read_error(int res, t_list *list);
size_t  coortoi(int row, int column, size_t size);
void    itocoor(int *x, int *y, size_t index, size_t size);
void	get_mask(unsigned short *top_row, unsigned short *left_col, size_t total_size);
void    tetro_translate(unsigned short *tetro, size_t total_size);
int     validate_tetro(unsigned short *tetro);
void    to_bits(char *s, unsigned short *dst, int iter);
int     read_input(const int fd, t_list **list, size_t *count);
int		add_tetro(unsigned short tetr, size_t count, t_list **lst);
#endif
