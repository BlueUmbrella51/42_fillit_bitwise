/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_pos.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 13:48:05 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/06 10:29:01 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		check_fit(uint16_t *map, t_tetro *tetro)
{
	if ((*(uint64_t *)(map + tetro->y) & (tetro->tetro >> tetro->x)) == 0)
		return (1);
	return (0);
}

static	int		same_rest(t_list *curr, t_list *rest)
{
	t_list	*r;
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

int				solve_ps(t_list *lst, t_tetro *tro, size_t size, uint16_t *map)
{
	while (tro->y <= size - tro->height)
	{
		tro->x = 0;
		while (tro->x <= size - tro->width)
		{
			if (check_fit(map, tro))
			{
				toggle_tetro(map, tro);
				if (solve_map(map, &lst->next, size))
					return (1);
				toggle_tetro(map, tro);
				if (same_rest(lst, lst->next))
				{
					tro->x = 0;
					tro->y = 0;
					return (0);
				}
			}
			tro->x++;
		}
		tro->y++;
	}
	tro->x = 0;
	tro->y = 0;
	return (0);
}
