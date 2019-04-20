/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 16:00:42 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/20 11:16:47 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstaddend(t_list **begin_list, void const *s, size_t n)
{
	t_list *new;
	t_list *tmp;

	tmp = *begin_list;
	new = ft_lstnew(s, n);
	if (!new)
		return ;
	if (*begin_list == NULL)
		*begin_list = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}