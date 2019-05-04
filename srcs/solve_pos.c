/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_pos.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 13:48:05 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 14:09:39 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static  int     check_fit(uint16_t *map, t_tetro *tetro)
{
    if((*(uint64_t *)(map + tetro->y) & (tetro->tetro >> tetro->x)) == 0)
        return (1);
    return (0);
}

static  int     same_rest(t_list *curr, t_list *rest)
{
    t_list  *r;
    t_tetro *rc;
    t_tetro *ch;

    r = rest;
    ch = curr->content;
    if (!r)
        return (0);
    while (r)
    {
        rc = r->content;
        if (ch->fpt != rc->fpt)
            return (0);
        r = r->next;
    }
    return (1);
}

int     solve_pos(t_list *curr, t_tetro *tetro, size_t map_size, uint16_t *map)
{
    while (tetro->y <= map_size - tetro->height)
    {
        tetro->x = 0;
        while (tetro->x <= map_size - tetro->width)
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
