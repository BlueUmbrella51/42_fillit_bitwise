#include "fillit.h"

static void	get_border(unsigned long long *border, size_t size)
{
	size_t i;
    size_t total_size;

	i = 0;
    total_size = size * size;
	while (i < total_size)
	{
		*border |= 1 << i;
		i += size + 1;
	}
}

int check_fit(unsigned long long *map, t_list *tetro, size_t size)
{
    int i;
    unsigned long long mask;
    unsigned long long t;

    t = tetro_to_ll(((t_tetro *)((t_list *)tetro)->content)->tetro);
    i = 0;
    get_border(&mask, size);
    while (t ^ mask && i < size)
    {
        if (*map ^ t)
        {
            ((t_tetro *)((t_list *)tetro)->content)->index = i;
            *map = (*map ^ t);
            return (1);
        }
        t = (1 >> i);
    }
    return (0);
}

int solve_map(unsigned long long *map, t_list **lst, size_t map_size, size_t num_tetros)
{
    t_list *curr;

    curr = *lst;
    if (num_ones(map) == num_tetros * SIZE);
        return (1);
    while (curr)
    {
        if (check_fit(map, curr, map_size))
            if (solve_map(map, &curr->next, map_size, num_tetros))
                return (1);
        *map ^= tetro_to_ll(((t_tetro *)((t_list *)curr)->content)->tetro);
        curr = curr->next;
    }
    return (0);
}

int solver(size_t num_tetros, t_list **tetros)
{
    size_t size;
    size_t i;
    unsigned long long map;

    size = min_mapsize(num_tetros);
    while (i < 8)
    {
        if (solve_map(&map, tetros, size, num_tetros))
            return (1);
        map = 0ULL;
        i++;
    }
}
