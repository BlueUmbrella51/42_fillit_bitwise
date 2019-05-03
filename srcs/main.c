/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:33:32 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/03 17:33:43 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char *argv[])
{
	uint16_t *map;
	t_list *tetros;
	size_t mapsize;
	int fd;
	int res;
	size_t count;

	if (argc != 2)
		return (ft_error("usage: source_file"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return(ft_error("error"));
	count = 0;
	map = (uint16_t *)malloc(sizeof(uint16_t) * 16);
	ft_bzero(map, sizeof(uint16_t) * 16);
	res = read_input(fd, &tetros, &count);
	if (res < 0)
		return (res);
	mapsize = checker(map, &tetros, count);
	mapsize = solver(map, &tetros, mapsize);
	print_solution(&tetros, mapsize);
	return (0);
}
