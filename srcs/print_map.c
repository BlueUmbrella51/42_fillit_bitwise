/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:46:05 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/03 18:03:26 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    print_map(uint16_t **map)
{
	int i;

	i = 0;
	while (i < 16)
	{
		printf("mp: %u\n", (*map)[i]);
		i++;
	}
}
