#include "fillit.h"

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
        toggle_tetro(curr->content, map);
        if (solve_it(&curr->next, map, mapsize))
            return (1);
        toggle_tetro(curr->content, map);
    }
    return (0);
}
