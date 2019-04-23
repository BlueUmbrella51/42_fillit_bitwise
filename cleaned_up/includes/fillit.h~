/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 08:38:03 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/22 14:48:39 by lravier       ########   odam.nl         */
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
	size_t index;
    char print;
}              t_tetro;

/** IN TETROMINOS SETUP **/
int		add_tetro(unsigned short tetr, size_t count, t_list **lst,
size_t total_size);
int		tetro_wh(t_tetro* t, unsigned short mask, unsigned short *visited,
size_t index);

/** IN TETRAMINOS VALIDATION **/
int		count_ones(unsigned short *tetro);
int		check_connections(size_t index, size_t total_size,
unsigned short *tetro);
int		check_edges(unsigned short *tetro, size_t total_size);
int		valid_characters(char *line, char f, char e);

/** IN TETRAMINOS UTILITY**/
void    tetro_translate(unsigned short *tetro, size_t total_size);
void    to_bits(char *s, unsigned short *dst, int iter, char f);
unsigned long long tetro_to_ll(t_tetro *t);
size_t	get_row(size_t index, size_t total_new, size_t width_old);

/** IN FILLIT UTILITY **/
size_t  coortoi(int row, int column, size_t size);
void    itocoor(int *x, int *y, size_t index, size_t size);
size_t  min_mapsize(size_t count);
void	print_tetro(unsigned short *dest, size_t size);

/** OTHER **/
int		ft_error(char *s);

/** IN READ_INPUT **/
int     validate_tetro(unsigned short *tetro, size_t total_size);
int     read_tetromino(int *lr, int fd, char **line, unsigned short *dst);
int     read_input(int fd, t_list **list, size_t *count);

/*
int     check_read_error(int res, t_list *list);
int     validate_tetro(unsigned short *tetro);
int     read_input(const int fd, t_list **list, size_t *count);
void	ft_translate_to_map_increase(t_tetro *t, size_t prev_size, size_t size,
size_t num_tetros);
*/
#endif
