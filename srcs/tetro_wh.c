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

int	count_ones(unsigned short *tetro)
{
	int count;

	count = 0;
	unsigned short n;
	n = *tetro;
	while (n != 0)
	{
		n &= n - 1;
		count++;
	}
	return (count);
}

int	tetro_wh(t_tetro* t, unsigned short tetro, size_t total_size)
{
	//save visited
	unsigned short visited;
	unsigned short mask;

	visited = 0;
	mask = 1U;
	//exit condition
	printf("INDEX %zu\n", t->index);
	printf("%s\n", ft_itoa_base(tetro, 2));
	printf("%s\n", ft_itoa_base(mask, 2));
	printf("WIDTH: %d\n", t->width);
	if (tetro == 0 || t->index >= 16)
	{
		printf ("got here! \n");
		exit(0);
	}
		//stop
	//mask = first one that hasnt been visited??
	else 
	{
		printf("%d", ((mask & tetro) == 0));
		if(~(mask & tetro))
		{
			t->index += 1;
			tetro_wh(t, tetro >> 1, total_size);
		}
//	return (0);
	//should it be only count if not yet visited??
	//go do recursion
		printf("STUFF: %zu, %d, %zu", total_size, SIZE, t->index);
		if (t->index < total_size - SIZE)
		{
			printf("hi");
			t->height += tetro_wh(t, (tetro ^ mask), total_size);
		}
		if (t->index >= SIZE)
			t->height += tetro_wh(t, (tetro ^ mask), total_size);
		if (!(t->index + 1 % SIZE == 0))
			t->width += tetro_wh(t, (tetro ^ mask), total_size);
		if (!(t->index % SIZE == 0))
			t->width += tetro_wh(t, (tetro ^ mask), total_size);
		printf("END---->");
		return (1);
	}
}