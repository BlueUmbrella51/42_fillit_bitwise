/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 13:55:52 by lravier       #+#    #+#                 */
/*   Updated: 2019/03/27 18:00:27 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	if (content == NULL)
	{
		lst->content_size = 0;
		lst->content = NULL;
	}
	else
	{
		lst->content_size = content_size;
		lst->content = (void *)malloc(content_size);
		if (!lst->content)
		{
			free(lst);
			return (NULL);
		}
		ft_memcpy(lst->content, content, content_size);
	}
	lst->next = NULL;
	return (lst);
}
