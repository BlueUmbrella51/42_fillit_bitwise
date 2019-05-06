/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_len.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 09:05:03 by lravier       #+#    #+#                 */
/*   Updated: 2019/05/06 09:05:51 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	lst_len(t_list **lst)
{
	size_t count;
	t_list *curr;

	curr = *lst;
	count = 0;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
