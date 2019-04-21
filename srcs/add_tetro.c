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

int		add_tetro(unsigned short tetr, size_t count, t_list **lst, size_t total_size)
{
	t_tetro *t;

	t = (t_tetro *)malloc(sizeof(t_tetro));
	if (!t)
		return (0);
	t->tetro = tetr;
//	printf("MKLIST %s\n", ft_itoa_base(t->tetro, 2));
	t->print = 'A' + count;
	t->index = 0;
	t->width = 0;
	t->height = 0;
	total_size = 1;
	tetro_wh(t, t->tetro, total_size);
	if (!(ft_lstaddend(lst, t, sizeof(t))))
		return (0);
	printf("%u", ((t_tetro *)((t_list *)*lst)->content)->tetro);
	return (1);
}
