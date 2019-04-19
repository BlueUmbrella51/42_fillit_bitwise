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

int    read_input(const int fd, t_list **list)
{
    int r;
    int i;
    unsigned short dest;
    char *line;

    r = 1;
    while(r == 1)
    {
        i = 0;
        while (i < 4)
        {
            r = get_next_line(fd, &line);
            if (r == -1)
                return (-1);
            if (ft_strlen(line) == 4)
                to_bits(line, &dest, i);
            else
                return (-1);
            i++;
        }                                                
        if (validate_tetro(&dest) == 1)
        {
            if(tetro_translate(&dest) == 1)
                ft_lstpushfront(&dest, list, 1);
        }
        dest = 0;
        r = get_next_line(fd, &line);
        if (line[0] == '\n' || line == NULL)
            continue;
        else
            break;
    }
    return (1);
}
