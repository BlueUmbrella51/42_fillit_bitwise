/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tetro_width_height.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 12:24:17 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/20 16:11:49 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	count_ones(unsigned short tetro)
{
	int count;
	count = 0;
	unsigned short n;
	n = tetro;
	while (n != 0)
	{
		n &= n - 1;
		count++;
	}
	return (count);
}

int	tetro_wh(t_tetro* t, unsigned short mask, unsigned short *visited, size_t total_size, size_t index)
{
	unsigned short prev_visited;

	if ((mask & t->tetro) != 0 && (*visited & mask) == 0)
	{
		prev_visited = *visited;
		*visited |= mask;
		if (count_ones(*visited) == 4 && (prev_visited ^ *visited) == 0)
			return (0);
		if (index < total_size - SIZE && (*visited & (mask << SIZE)) == 0)
			t->height += tetro_wh(t, mask << SIZE, visited, total_size, index + SIZE);
		if (index >= SIZE && (*visited & (mask >> SIZE)) == 0)
			t->height += tetro_wh(t, mask >> SIZE, visited, total_size, index - SIZE);
		if (index % SIZE != 0 && (*visited & (mask >> 1)) == 0)
			t->width += tetro_wh(t, mask >> 1, visited, total_size, index - 1);
		if ((index + 1) % SIZE != 0 && (*visited & (mask << 1)) == 0)
			t->width += tetro_wh(t, mask << 1, visited, total_size, index + 1);
		return (1);
	}
	return (0);
}