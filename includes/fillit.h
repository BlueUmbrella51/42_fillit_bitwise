
#ifndef FILLIT_H
#define FILLIT_H
# include "libft.h"
# include <stdint.h>
# include "get_next_line.h"
# define SIZE 4

#include <stdio.h>

typedef struct s_tetro
{
    uint64_t tetro;
    uint16_t fpt;
    unsigned char x;
    unsigned char y;
    size_t order;
    size_t width;
    size_t height;
    t_list *last;
    int type;
    char print;
}              t_tetro;

/** IN READ INPUT **/
int		read_input(int fd, t_list **list, size_t *count);
int		add_tetro(uint16_t  tetr, size_t count, t_list **lst);

/** IN UTILITIES1 **/
size_t  get_row(size_t index, int o_size);
void    coortoi(size_t *index, int x, int y, size_t width);
size_t    convert_index(size_t index, size_t o_size, size_t n_width);
uint64_t convert_sll(uint16_t t);
void	itocoor(int *x, int *y, size_t index, size_t size);

/** IN UTILITIES2 **/
int		ft_error(char *s);
int     count_ones(uint16_t *tetro);
size_t find_first(uint16_t t);

/** IN READ TETRO **/
int		read_tetromino(int *lr, int fd, char **line, uint16_t  *dst);

/** IN VALIDATE TETRO **/
int		validate_tetro(uint16_t *tetro, size_t total_size);

/** IN CHECKER **/
int     checker(uint16_t *map, t_list **tetros, size_t num_tetros);

/** IN TETRO TRANSLATE **/
void    tetro_translate (uint16_t *tetro, size_t total_size);

/** IN MAP **/
int     initialize_map(uint16_t **map);

/** IN FIND MAPSIZE **/
int    find_permutations(t_list *lst, t_list *pos, uint16_t *map, size_t num_tetros, int *found);

/** IN SOLVER **/
int     solver(uint16_t *map, t_list **tetros, size_t map_size);

void    list_sort(t_list *tetros);

/** TEMP!! **/
void    print_tetro(t_list *curr);
void    print_map(uint16_t **map);
void    print_us(uint16_t *map);
void    print_lst(t_list **lst);

void    print_solution (t_list **tetros, size_t mapsize);

#endif
