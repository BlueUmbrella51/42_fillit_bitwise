/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 10:29:14 by lravier       #+#    #+#                 */
/*   Updated: 2019/03/25 10:52:01 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *arr, int c, size_t n)
{
	unsigned char	sym;
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char*)arr;
	i = 0;
	sym = (unsigned char)c;
	while (i < n)
	{
		*ptr = c;
		ptr++;
		i++;
	}
	return (arr);
}
