/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memplen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 15:09:37 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/12 15:46:16 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memplen(void *src, void *tofind, size_t len)
{
	size_t i;

	i = 0;
	while (&src[i] != tofind && i < len)
		i++;
	return (i);
}
