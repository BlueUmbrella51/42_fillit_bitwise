/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_for_map_increase.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:48:09 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/20 18:14:23 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//0100 1110 0000 0000
//01001 11000 00000 00000 00000
//01000 1	

#include "fillit.h"

void	ft_translate_for_map_increase(unsigned long long *map, size_t prev_size, size_t size, size_t num_tetros)
{
	unsigned long long new;
	size_t diff;
	unsigned long long mask;
	size_t offset;

	diff = size - prev_size;
	offset = (num_tetros * 4 - 1) * diff;
	new = *map << diff;
	mask = 1 << 0;
//skip all bits that are 0 and then skip first 1
	while (offset != diff)
	{
//skip until 'last' 1 is found
		while (mask ^ new)
			mask <<= 1;
//remove one that is found, then add it back later;
		new ^= mask;
		mask >>= offset;
		new |= mask;
		offset -= diff;
	}
	*map = new;
}

unsigned long long	tetro_to_ll(t_tetro *t)
{
	unsigned long long res;
	unsigned long long mask;
	size_t offset;

	res = t->tetro;
	res <<= 12;
	offset = 3;
	mask = 1 << 0;
	while (offset != 1)
	{
		while (mask ^ res)
			mask <<= 1;
		res ^= mask;
		mask >>= offset;
		res |= mask;
		offset -= 1;
	}
	return (res);
}
