/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_bits.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 12:35:15 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/25 12:47:25 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void add_bits(t_tetro_new tetro, t_field *field)
{
    toggle_bit(tetro.index1, field->size, field);
    toggle_bit(tetro.index2, field->size, field);
    toggle_bit(tetro.index3, field->size, field);
    toggle_bit(tetro.index4, field->size, field);
}
