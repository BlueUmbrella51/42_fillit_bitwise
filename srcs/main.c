/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 13:56:49 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/25 17:30:25 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char *argv[])
{
	t_list *tetros;
	int fd;
	int res;
	size_t count;
	t_field field;

	count = 0;
	if (argc != 2)
		return (ft_error("Invalid number of input files"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("File could not be opened"));
	res	= read_input(fd, &tetros, &count);
	if (res != 0)
		return (-1);
	res = solver(&field, count, &tetros);
	return (0);
}
