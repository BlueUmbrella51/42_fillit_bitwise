/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_bits.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 13:00:45 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/19 13:01:07 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    print_tetro( unsigned const short *dest, size_t size)
{
    unsigned short tmp;
    size_t width;

    width = ft_sqrt(size);
    tmp = *dest;
    while (size)
    {
        tmp = tmp >> (size - 1);
        if (tmp & 1)
            ft_putchar('#');
        else
            ft_putchar('.');
        size--;
        tmp = *dest;
        if (size % width == 0)
            ft_putchar('\n');
    }
}