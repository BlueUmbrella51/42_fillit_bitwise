#include "fillit.h"

size_t  min_mapsize(size_t num_tetros)
{
    size_t i;

    i = 2;
    while (i * i < (num_tetros * SIZE))
        i++;
    return (i);
}

static size_t count_dup(t_list **lst, size_t num_tetros)
{
    size_t res;
    t_list *curr;
    t_list *check;
    size_t i;
    int dups[num_tetros];

    ft_bzero(dups, num_tetros);
    res = 0;
    i = 0;
    if (!*lst)
        return (0);
    curr = (*lst)->next;
    check = *lst;
    while (i < num_tetros && check)
    {
        while (curr)
        {
            if (((t_tetro *)((t_list *)curr)->content)->tetro ==
            ((t_tetro *)((t_list *)check)->content)->tetro)
                dups[i] += 1;
            curr = curr->next;
        }
        check = check->next;
        i++;
    }
    i = 0;
    while (i < num_tetros)
    {
        res += dups[i];
        i++;
    }
    return (res);
}

static int get_size(t_list **tetros, size_t num_tetros, uint16_t *map)
{
    size_t start_size;
    size_t duplicates;
    int found;

    found = 0;
    start_size = min_mapsize(num_tetros);
    duplicates = count_dup(tetros, num_tetros);
//    printf("duplictaes: %zu\n", duplicates);
    if (duplicates < num_tetros / 2 || num_tetros < 6)
        return (start_size);
    //when do we check if fits with other method?
    while (!find_permutations(*tetros, *tetros, map, start_size, &found))
    {
        ft_bzero(map, sizeof(uint16_t) * 16);
        start_size++;
    }
//    printf("start size checker: %zu\n", start_size);
    return (start_size);
}

int     checker(uint16_t *map, t_list **tetros, size_t num_tetros)
{
    size_t min_size;

    min_size = get_size(tetros, num_tetros, map);
    list_sort(*tetros);
    return (min_size);
}