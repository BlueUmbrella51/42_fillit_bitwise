/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_for_map_increase.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:48:09 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/20 17:42:29 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//0100 1110 0000 0000
//01001 11000 00000 00000 00000
//01000 1	


void	ft_to_ll(t_tetro *t)
{
	ft_translate_for_map_increase(t, 16, 64);
}

void	ft_translate_for_map_increase(t_tetro *t, size_t prev_size, size_t size, size_t num_tetros)
{
	unsigned long long new;
	size_t diff;
	unsigned long long mask;
	unsigned long long offsetter;
	size_t offset;

	diff = size - prev_size;
	offset = (num_tetros * 4 - 1) * diff;
	new = t->tetro << diff;
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
}
