/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftd_memdup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 10:04:22 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/12 15:42:58 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ftd_memdup(void **dst, void *src, size_t len)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)*dst;
	i = 0;
	destination = ft_memalloc(len);
	if (!dst)
		return (0);
	while (i < len)
	{
		destination[i] = source[i];
		i++;
	}
	ft_memdel(&src);
	*dst = (void *)destination;
	return (1);
}
