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

int main(int argc, char **argv)
{
    t_list *tetros;
    int fd;
    int res;
    size_t count;
    size_t map_size;

    tetros = NULL;
    count = 0;
    if (argc == 1)
    {
        printf("error: no input file\n");
        return (0);
    }
    fd = open(argv[1], O_RDONLY);
    if (!fd || fd <= 0)
        ft_putendl("\nerror: file could not be opened");
    else
        printf("\nfile was opened succesfully, fd == %i\n", fd);
    res = read_input(fd, &tetros, &count);
    if(check_read_error(res, tetros) == 0)
        return (0);
    printf("\n %lu tetros were found in the input file\n", count);
    map_size = find_mapsize(count);
    printf("\n The starting mapsize is %lu\n", map_size);
    close(fd);
    return (0);
}