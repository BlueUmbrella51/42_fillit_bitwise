/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 17:15:29 by lravier       #+#    #+#                 */
/*   Updated: 2019/03/21 17:25:39 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *first;

	first = (char *)s;
	while (*first)
	{
		if (*first == c)
			return (first);
		first++;
	}
	if (*first == c)
		return (first);
	return (NULL);
}
