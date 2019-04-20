/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_tetramino.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 13:49:09 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/20 14:37:58 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		add_tetro(unsigned short tetr, size_t count, t_list **lst)
{
	t_tetro *t;

	t = (t_tetro *)malloc(t_tetro);
	if (!t)
		return (0);
	t->tetro = tetr;
	t->width = 0;
	t->height = 0;
	t->print = 'A' + count;
	t->index = 0;
	if (!(lst_addend(lst, t)))
		return (0);
	return (1);
}
