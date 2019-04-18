/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoupper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 15:41:11 by lravier       #+#    #+#                 */
/*   Updated: 2019/03/29 18:46:45 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtoupper(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_islower(s[i]))
			ft_toupper(s[i]);
		i++;
	}
}
