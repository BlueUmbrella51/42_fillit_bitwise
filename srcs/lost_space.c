/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lost_space.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 14:28:22 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 14:30:13 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	size_t	count_adjacent(uint16_t *map, uint16_t *visited, uint16_t mask, size_t y, size_t x, size_t *count, size_t mapsize)
{
	if ((((*(map + y)) & mask) == 0) && ((mask & (*(visited + y))) == 0))
	{
		((*(visited + y)) |= mask);
		if (x > 0)
			*count += count_adjacent(map, visited, (mask << 1), y, x - 1, count, mapsize);
		if (x < (mapsize - 1))
			*count += count_adjacent(map, visited, (mask >> 1), y, x + 1, count, mapsize);
		if (y > 0)
			*count += count_adjacent(map, visited, mask, y - 1, x, count, mapsize);
		if (y < (mapsize - 1))
			*count += count_adjacent(map, visited, mask, y + 1, x, count, mapsize);
		return (1);
	}
	return (0);
}

size_t			lost_space(uint16_t *map, size_t mapsize)
{
	uint16_t	mask;
	uint16_t	visited[16];
	size_t		x;
	size_t		y;
	size_t		count;
	size_t		total;

	y = 0;
	count = 1;
	total = 0;
	x = 0;
	while (x < 16)
	{
		visited[x] = 0;
		x++;
	}
	while (y < mapsize)
	{
		x = 0;
		mask = (1 << 15);
		while (x < mapsize)
		{
			if (((*(map + y)) & mask) == 0 && ((mask & (*(visited + y))) == 0))
			{
				count_adjacent(map, visited, mask, y, x, &count, mapsize);
				if (count < 4)
 					total += count;
			}
			count = 1;
			x++;
			mask >>= 1;
		}
		y++;
	}
	return (total);
}
