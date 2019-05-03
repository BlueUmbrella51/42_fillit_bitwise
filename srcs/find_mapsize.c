#include "fillit.h"

void    swap_list(t_list *curr, t_list *new)
{
    t_tetro *tmp;

    tmp = curr->content;
    curr->content = new->content;
    new->content = tmp;
}

int     compare_lst(t_list *curr, t_list *comp)
{
    if (((t_tetro *)((t_list *)curr)->content)->tetro == ((t_tetro*)((t_list *)comp)->content)->tetro)
        return (1);
    return (0);
}

int     should_swap(t_list *start, t_list *curr)
{
    t_list *iter;

    iter = start;
    while (iter != curr && iter)
    {
        if (compare_lst(curr, iter))
            return (0);
        iter = iter->next;
    }
    return (1);
}

static void    toggle_tetro(t_list *t, uint16_t *map)
{
    t_tetro *tetro;

    tetro = t->content;
    *((uint64_t *)(map + tetro->y)) ^= (tetro->tetro >> tetro->x);
}

static int check_tetro(t_list *curr, uint16_t *map, size_t mapsize)
{
    t_tetro *tetro;
    t_list *last;
    size_t index;

    index = 0;
    tetro = curr->content;
    last = tetro->last;
    if (last)
    {
        index = ((t_tetro *)((t_list *)last)->content)->x +
        ((t_tetro *)((t_list *)last)->content)->y * mapsize;
        tetro->y = index / mapsize;
    }
    else
        tetro->y = 0;
    while (tetro->y <= mapsize - tetro->height)
    {
        tetro->x = 0;
        if (tetro->y != 0)
            tetro->x = index % mapsize;
        while (tetro->x <= mapsize - tetro->width)
        {
            if (((*(uint64_t *)(map + tetro->y)) & (tetro->tetro >> tetro->x)) == 0)
                return (1);
            tetro->x++;
        }
        tetro->y++;
    }
    tetro->x = 0;
    tetro->y = 0;
    return (0);
}

int solve_it(t_list **tetros, uint16_t *map, size_t mapsize)
{
    t_list *curr;

    if (!*tetros)
        return(1);
    curr = *tetros;
    if (curr == NULL)
        return (1);
    if (mapsize < ((t_tetro *)((t_list *)curr)->content)->width || 
    mapsize < ((t_tetro *)((t_list *)curr)->content)->height)
        return (0);
    if (check_tetro(curr, map, mapsize))
    {
        toggle_tetro(curr, map);
        if (solve_it(&curr->next, map, mapsize))
            return (1);
        toggle_tetro(curr, map);
    }
    return (0);
}

int test_it(t_list **tetros, uint16_t *map, size_t min_size)
{
    return(solve_it(tetros, map, min_size));
}

int    find_permutations(t_list *lst, t_list *pos, uint16_t *map, size_t min_size, int *found)
{
    t_list *curr;
//    print_lst(&pos);
    if (!pos && *found == 0)
    {
        ft_bzero(map, sizeof(uint16_t) + 16);
        *found = test_it(&lst, map, min_size);
    }
    if (*found)
        return (1);
    curr = pos;
    while (curr)
    {
        if (*found)  
            return (1);
        if(should_swap(pos, curr))
        {
            swap_list(pos, curr);
            find_permutations(lst, pos->next, map, min_size, found);
            if (*found)  
                return (1);
            swap_list(pos, curr);
        }
        curr = curr->next;
    }
    return (0);
}
