/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitboards.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 10:35:17 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/18 11:34:27 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int count_ones(unsigned short *tetro)
{
    unsigned short tmp;
    int count;

    count = 0;
    tmp = *tetro;
    while (tmp)
    {
        count += tmp & 1;
        tmp >>= 1;
    }
    return (count);
}

static int is_one(unsigned short *tetro, size_t index)
{
    unsigned short tmp;
    unsigned short mask;

    tmp = *tetro;
    mask = 1 << (index - 1);
    tmp = tmp & mask;
    if (tmp == 0)
        return (0);
    return (1);
}

static int count_sides(size_t index, unsigned short *tetro)
{
    int x;
    int y;
    int count;
    size_t total_blocks;

    total_blocks = 16;
    x = 0;
    y = 0;
    count = 0;
    itocoor(&x, &y, total_blocks - index, 4);

    if (x < 4)
        count += is_one(tetro, index - 1);
    if (y < 4)
        count += is_one(tetro, index - 4);
    if (y > 0)
        count += is_one(tetro, index  + 4);
    if (x > 0)
        count += is_one(tetro, index + 1);
    return (count);
}

static  int tetro_check(unsigned short *tetro)
{
    int count;
    size_t index;

    count = 0;
    index = 16;
    while (index)
    {
        if(is_one(tetro, index))
            count += count_sides(index, tetro);        
        index--;
    }
    if (count == 6 || count == 8)
        return (1);
    return (0);
}

int validate_tetro(unsigned short *tetro)
{   
    if (!tetro)
        return (-1);
    if (*tetro >= 61444)
        return (0);
    if(count_ones(tetro) != 4)
        return (0);
    if(tetro_check(tetro) == 0)
        return (0);
    return (1);
}