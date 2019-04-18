/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 19:18:59 by lravier       #+#    #+#                 */
/*   Updated: 2019/03/28 10:54:28 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	res = (char *)malloc((sizeof(char) * size) + 1);
	if (res)
	{
		ft_bzero(res, size + 1);
		return (res);
	}
	else
		return (NULL);
}
