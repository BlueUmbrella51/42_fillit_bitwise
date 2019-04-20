/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitboards.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 10:35:17 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/20 10:50:01 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_mask(unsigned short *top_row, unsigned short *left_col,
size_t width, size_t total_size)
{
	size_t i;

	i = total_size - width;
	while (i < total_size)
	{
		*top_row |=  1 << i;
		i++;
	}
	i = width - 1;
	while (i < total_size)
	{
		*left_col |= 1 << i;
		i += width;
	}
}

void tetro_translate (unsigned short *tetro, size_t width, size_t total_size)
{
	unsigned short top_row;
	unsigned short left_col;

	top_row = 0;
	left_col = 0;
	get_mask(&top_row, &left_col, width, total_size);
	while ((*tetro & top_row) == 0)
		*tetro <<= width;
	while ((*tetro & left_col) == 0)
		*tetro <<= 1;
}
