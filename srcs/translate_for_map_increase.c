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
size_t	get_row(size_t index, int total_new, int width_old)
{
	size_t test;
	size_t row = 0;

	test = total_new - width_old;
	while (index <= test)
	{
		test -= width_old;
		row++;
	}
	return (row);
}
void	ft_translate_for_map_increase(unsigned long long *map, size_t prev_size, size_t size, size_t num_tetros)
{
//both sizes in width, not total 
	unsigned long long tmp;
	unsigned long long res;
	unsigned long long mask;
	size_t diff;
	size_t offset;
	size_t row;
	size_t j;
	size_t i;

	j = 0;
	i = 1;
	res = 0ULL;
	diff = size - prev_size;
	offset = prev_size;
	tmp = *map;
	tmp <<= (size * size) - (prev_size * prev_size);
	mask = 1ULL;
//skip all bits that are 0 and then skip first 1
	while (j < (num_tetros * 4 - 1))
	{
//skip until 'last' 1 is found
		while ((tmp & mask) == 0)
		{
			mask = (1ULL << i);
			i++;
		}
//remove one that is found, then add it back later;
		row = get_row(i, size * size, prev_size);
		tmp ^= mask;
		mask >>= offset * row;
//		i -= offset * row;
		res |= mask;
		j++;
	}
	res |= tmp;
	*map = res;
}

unsigned long long	tetro_to_ll(t_tetro *t)
{
	unsigned long long res;
	unsigned long long tmp;
	unsigned long long mask;
	int j;
	size_t i;
	size_t row;

	j = 0;
	row = 1;
	res = 0ULL;
	tmp = (unsigned long long)t->tetro;
	tmp <<= 48ULL;
	i = 1;
	mask = 1ULL;
	while (j < SIZE - 1)
	{
		while ((tmp & mask) == 0)
		{
			mask = (1ULL << i);
			i++;
		}
		row = get_row(i, 64, 4);
		tmp ^= mask;
		mask >>= SIZE * row;
		res |= mask;
		j++;
	}
	res |= tmp;
	return (res);
}
