#include "fillit.h"

int count_longs(unsigned long long *tetro)
{
    unsigned long long tmp;
    int count;

    count = 0;
    tmp = *tetro;
    while (tmp)
    {
        count += tmp & 1;
        tmp >>= 1;
    }
    return (count);
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
    unsigned long long mask;
    unsigned long long t;

    mask = 0ULL;
    t = tetro_to_ll(((t_list *)tetro)->content);
    i = 0;
    get_border(&mask, size);
    printf("BORDER: %llu\n", mask);
    while (i < size)
    {
        if ((*map & t) == 0)
        {
            ((t_tetro *)((t_list *)tetro)->content)->index = i;
            *map |= t;
            printf("MAP: %llu\nINDEX: %zu\n", *map, i);
            return (1);
        }
        t >>= 1;
        printf("TETRO: %llu\n", t);
        i++;
    }
    return (0);
}

int solve_map(unsigned long long *map, t_list **lst, size_t map_size, size_t num_tetros)
{
    t_list *curr;

    curr = *lst;
    if (count_longs(map) == (int)num_tetros * SIZE)
        return (1);
    while (curr)
    {
        if (check_fit(map, curr, map_size))
            if (solve_map(map, &curr->next, map_size, num_tetros))
                return (1);
        *map ^= tetro_to_ll(((t_list *)curr)->content);
        curr = curr->next;
//        exit(0);
    }
    return (0);
}

int solver(unsigned long long *map, size_t num_tetros, t_list **tetros)
{
    size_t size;

    size = min_mapsize(num_tetros);
    printf("MAP_SIZE: %zu\nNUM_TETROS: %zu\n", size, num_tetros);
    while (size < 8)
    {
        printf("in while\n");
        if (solve_map(map, tetros, size, num_tetros))
            return (1);
        map = 0ULL;
        size++;;
    }
    return (0);
}
