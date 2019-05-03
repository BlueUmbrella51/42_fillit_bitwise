#include "fillit.h"


static void    swap_list(t_list *curr, t_list *new)
{
    t_tetro *tmp;

    tmp = curr->content;
    curr->content = new->content;
    new->content = tmp;
}

static int     compare_lst(t_list *curr, t_list *comp)
{
    if (((t_tetro *)((t_list *)curr)->content)->tetro == ((t_tetro*)((t_list *)comp)->content)->tetro)
        return (1);
    return (0);
}

static int     should_swap(t_list *start, t_list *curr)
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

int    find_permutations(t_list *lst, t_list *pos, uint16_t *map, size_t min_size, int *found)
{
    t_list *curr;
    if (!pos && *found == 0)
    {
        ft_bzero(map, sizeof(uint16_t) + 16);
        *found = solve_it(&lst, map, min_size);
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