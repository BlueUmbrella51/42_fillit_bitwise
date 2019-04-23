/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_tetramino.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 13:49:09 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/20 17:52:02 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_first(t_tetro *t)
{
	unsigned short mask;
	size_t i;

	i = 0;
	mask = 1U;
	while ((mask & t->tetro) == 0)
	{
		mask = mask << 1;
		i++;
	}
	t->index = i;
}

static int		is_smashboy(unsigned short tetro)
{
	unsigned short mask;
	mask = 52224;
	print_tetro(&mask, 16);
	if ((tetro ^ mask) == 0)
		return (1);
	return (0);
}

int		add_tetro(unsigned short tetr, size_t count, t_list **lst, size_t total_size)
{
	t_tetro *t;
	unsigned short mask;
	unsigned short visited;

	visited = 0;
	t = (t_tetro *)malloc(sizeof(t_tetro));
	if (!t)
		return (0);
	t->tetro = tetr;
//	printf("MKLIST %s\n", ft_itoa_base(t->tetro, 2));
	t->print = 'A' + count;
	find_first(t);
	mask = (1 << t->index);
	t->width = 1;
	t->height = 1;
	total_size = SIZE * SIZE;
	if (is_smashboy(t->tetro))
	{
		t->width = SIZE / 2;
		t->height = SIZE / 2;
	}
	else
		tetro_wh(t, mask, &visited, total_size, t->index);
	printf("ADD TETRO WIDTH %d\n", t->width);
	printf("ADD TETRO HEIGHT %d\n", t->height);
	if (!(ft_lstaddend(lst, t, sizeof(t))))
		return (0);
	return (1);
}
