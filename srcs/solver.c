#include "fillit.h"

static void    toggle_tetro(uint16_t *map, t_tetro *tetro)
{
    *(uint64_t *)(map + tetro->y) ^= (tetro->tetro >> tetro->x);
}

static int     check_fit(uint16_t *map, t_tetro *tetro)
{
    if((*(uint64_t *)(map + tetro->y) & (tetro->tetro >> tetro->x)) == 0) 
        return (1);
    return (0);
}

int     same_rest(t_list *curr, t_list *rest)
{
    t_list *r;
    t_tetro *rc;
    t_tetro *ch;
    
    r = rest;
    ch = curr->content;
    if (!r)
        return (0);
    while (r)
    {
        rc = r->content;
        if  (ch->type != rc->type)
            return (0);
        r = r->next;
    }
    return (1);
}

int     solve_map(uint16_t *map, t_list **tetros, size_t map_size)
{
    size_t index;
    t_list *curr;
    t_tetro *tetro;
    t_list *last;

    curr = *tetros;
    if (!curr)
    {
        return (1);
    }
    tetro = curr->content;
    last = ((t_tetro *)((t_list *)curr)->content)->last;
    index = 0;
    if (map_size < tetro->width || map_size < tetro->height)
        return (0);
    if (last)
    {
        index = ((t_tetro *)((t_list *)last)->content)->x + ((t_tetro *)((t_list *)last)->content)->y * map_size;
        tetro->y = index / map_size;
    }
    else
        tetro->y = 0;
    while (tetro->y <= map_size - tetro->height)
    {
        tetro->x = 0;
/*        if (tetro->y != 0)
            tetro->x = index % map_size;
*/        while (tetro->x <= map_size - tetro->width)
        {
            if (check_fit(map, tetro))
            {
                toggle_tetro(map, tetro);
                if (solve_map(map, &curr->next, map_size))
                    return (1); 
                toggle_tetro(map, tetro);
                if (same_rest(curr, curr->next))
                {
                    tetro->x = 0;
                    tetro->y = 0;
                    return (0);
                }
            }
            tetro->x++;
        }
        tetro->y++;
    }
    tetro->x = 0;
    tetro->y = 0;
    return (0);
}

int     solver(uint16_t *map, t_list **tetros, size_t map_size)
{
    while (map_size <= 16)
    {
        ft_bzero(map, sizeof(uint16_t) * 16);
        if (solve_map(map, tetros, map_size))
            return (map_size);
        map_size++;
    }
    return (0);
}
