/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_solver.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 16:52:00 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/25 16:54:39 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

int check_fit_field(t_field map, t_field tmp)
{
    tmp.top_left = tmp.top_left ^ map.top_left;
    map.top_left = tmp.top_left | map.top_left;
    if (map.top_left != tmp.top_left)
        return (0);
    tmp.top_right = tmp.top_right ^ map.top_right;
    map.top_right = tmp.top_right | map.top_right;
    if (map.top_right != tmp.top_right)
        return (0);
    tmp.bot_left = tmp.bot_left ^ map.bot_left;
    map.bot_left = tmp.bot_left | map.bot_left;
    if (map.bot_left != tmp.bot_left)
        return (0);
    tmp.bot_right = tmp.bot_right ^ map.bot_right;
    map.bot_right = tmp.bot_right | map.bot_right;
    if (map.bot_right != tmp.bot_right)
        return (0);
    return (1);
}

t_field combine_fields(t_field map, t_field tmp)
{
    t_field dest;

    dest.top_left = map.top_left | tmp.top_left;
    dest.top_right = map.top_right | tmp.top_right;
    dest.bot_left = map.bot_left | tmp.bot_left;
    dest.bot_right = map.bot_right | tmp.bot_right;
    return (dest);
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

int solve_pos(t_field *map, t_tetro *tetro)
{
    t_field tmp;

    tmp = create_field(256);
    toggle_bits(*tetro, &tmp);
    while (check_fit_field(*map, tmp) == 0)
    {
        toggle_bits(*tetro, &tmp);
        (*tetro).pl_index1++;
        (*tetro).pl_index2++;
        (*tetro).pl_index3++;
        (*tetro).pl_index4++;
        toggle_bits(*tetro, &tmp);
    }
    *map = combine_fields(*map, tmp);
}

int solve_map(t_field *field, t_list **list, size_t map_size, size_t num_tetros)
{
    t_list *curr;

    curr = *lst;
    if (count_field(field, map_size) == (int)num_tetros * SIZE)
        return (1);
    while(curr)
    {
        if(solve_pos(field, curr->content))
            if(solve_map(field, &curr->next, map_size, num_tetros))
                return (1);
        curr = curr->next;
    }
    return (0);
}
