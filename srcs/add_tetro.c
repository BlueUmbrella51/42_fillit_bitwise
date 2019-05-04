/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_tetro.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:44:09 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/04 13:12:09 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	size_t	find_first(uint16_t tetro)
{
	uint16_t	mask;
	size_t		i;

	i = 0;
	mask = 1U;
	while ((mask & tetro) == 0)
	{
		mask = (mask << 1U);
		i++;
	}
	return (i);
}

static int		tetro_wh(t_tetro *t, uint16_t msk, uint16_t *visit, size_t i)
{
	uint16_t	prev_visited;
	size_t		total_size;

	total_size = SIZE * SIZE;
	if ((mask & t->fpt) != 0 && (*visited & mask) == 0)
	{
		prev_visited = *visited;
		*visited |= mask;
		if (count_ones(visited) == 4 && (prev_visited ^ *visited) == 0)
			return (0);
		if (index < total_size - SIZE && (*visited & (mask << SIZE)) == 0)
			t->height += tetro_wh(t, mask << SIZE, visited, index + SIZE);
		if (index >= SIZE && (*visited & (mask >> SIZE)) == 0)
			t->height += tetro_wh(t, mask >> SIZE, visited, index - SIZE);
		if (index % SIZE != 0 && (*visited & (mask >> 1)) == 0)
			t->width += tetro_wh(t, mask >> 1, visited, index - 1);
		if ((index + 1) % SIZE != 0 && (*visited & (mask << 1)) == 0)
			t->width += tetro_wh(t, mask << 1, visited, index + 1);
		return (1);
	}
	return (0);
}

static	void	find_last(t_list **lst, t_tetro *t)
{
	t_list *tmp;
	t_list *last;

	tmp = *lst;
	while (tmp)
	{
		if (((t_tetro *)(tmp->content))->fpt == t->fpt)
		{
			last = tmp;
			t->last = last;
		}
		tmp = tmp->next;
	}
}

void			set_attributes(uint16_t tetr, size_t count, t_tetro *t)
{
	t->fpt = tetr;
	t->tetro = convert_sll(tetr);
	t->print = 'A' + (count - 1);
	t->order = count;
	t->last = NULL;
	t->x = 0;
	t->y = 0;
	t->width = 1;
	t->height = 1;
}

int				add_tetro(uint16_t tetr, size_t count, t_list **lst)
{
	t_tetro		*t;
	size_t		index;
	uint16_t	mask;
	uint16_t	visited;

	t = (t_tetro *)malloc(sizeof(t_tetro));
	if (!t)
		return (0);
	set_attributes(tetr, count, t);
	index = find_first(tetr);
	mask = (1U << index);
	visited = 0UL;
	if (t->fpt == 52224)
	{
		t->width = 2;
		t->height = 2;
	}
	else
		tetro_wh(t, mask, &visited, index);
	find_last(lst, t);
	if (!(ft_lstaddend(lst, t, sizeof(t_tetro))))
		return (0);
	return (1);
}
