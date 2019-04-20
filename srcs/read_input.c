/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitboards.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 10:35:17 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/20 14:45:15 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int    read_input(const int fd, t_list **list, size_t *count)
{
    int r;
    int i;
	size_t total_size;
    unsigned short dest;
    char *line;

	total_size = SIZE * SIZE;
    dest = 0;
    r = 1;
    while(r == 1)
    {
        if(*count > 25)
            return (-7);
        i = 0;
        ft_putchar('\n');
        while (i < 4)
        {
            r = get_next_line(fd, &line);
            if (r <= 0)
                return (r);
            ft_putendl(line);
            if (ft_strlen(line) == 4)
                to_bits(line, &dest, i);
            else
                return (-2);
            i++;
        }
        *count = *count + 1;
        printf("\n This is tetro : %lu\n", *count);
        ft_putchar('\n');
        printf("The current tetro == %u\n", dest);
        printf("the current tetro in binary == %s\n", ft_itoa_base(dest, 2));                                              
        if (validate_tetro(&dest) == 1)
        {
            tetro_translate(&dest, total_size);
            add_tetro(dest, *count, list);
        }
        else
            return (-4);
        dest = 0;
        r = get_next_line(fd, &line);
        if (r == 0)
            return (0);
        if (line[0] == '\n' || line[0] == '\0')
            continue;
        else
            return (-5);
    }
    return (-6);
}
