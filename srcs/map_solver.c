#include "fillit.h"

int count_field(t_field *field, size_t size)
{
    int res;
    size_t total;
    size_t i;
    size_t j;

    j = 0;
    i = 0;
    res = 0;
    total = size * size;
    //only count part of quadrants 
    while (i < 8 && i < size)
    {
        while (j < 8 && j < size)
        {
            res += is_one(coortoi(i, j, total), field->top_left);
            j++;
        }
        while (j < 16 && j < size)
        {
            res += is_one(coortoi(i, j, total), field->top_right);
            j++;
        }
        i++;
        j = 0;
    }
    while (i < 16 && i < size)
    {
        while (j < 8 && j < size)
        {
            res += is_one(coortoi(i, j, total), field->bot_left);
            j++;
        }
        while (j < 16 && j < size)
        {
            res += is_one(coortoi(i, j, total), field->bot_right);
            j++;
        }
        j = 0;
        i++;
    }
    return (res);
}

static void	get_border(unsigned long long *border, size_t size)
{
	size_t i;
    size_t total_size;

	i = 0;
    total_size = size * size;
	while (i < total_size)
	{
		*border |= (1 << i);
		i += size + 1;
	}
}

int check_fit(unsigned long long *map, t_list *tetro, size_t size)
{
    size_t i;
    unsigned long long t;

    t = tetro_to_ll(((t_list *)tetro)->content);
    i = 0;
    while (i < size)
    {

    }
}

void    remove_tetro(t_list *tetro, t_field *field)
{

}

int solve_map(t_field *field, t_list **lst, size_t map_size, size_t num_tetros)
{
    t_list *curr;

    curr = *lst;
    if (count_field(field, map_size) == (int)num_tetros * SIZE)
        return (1);
    while (curr)
    {
        if (check_fit(field, curr, map_size))
            if (solve_map(field, &curr->next, map_size, num_tetros))
                return (1);
        remove_tetro(field, curr);
        curr = curr->next;
//        exit(0);
    }
    return (0);
}

void    reset_field(t_field *field)
{
    field->top_left = 0ULL;
    field->bot_left = 0ULL;
    field->top_right = 0ULL;
    field->bot_right = 0ULL;
}

int solver(t_field *field, size_t num_tetros, t_list **tetros)
{
    size_t size;

    size = min_mapsize(num_tetros);
    printf("MAP_SIZE: %zu\nNUM_TETROS: %zu\n", size, num_tetros);
    while (size < 16)
    {
        printf("in while\n");
        *field = create_field(size * size);
        if (solve_map(field, tetros, size, num_tetros))
            return (1);
        reset_field(field);
        size++;
    }
    return (0);
}
