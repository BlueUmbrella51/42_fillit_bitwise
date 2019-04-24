/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 13:56:49 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/22 14:05:20 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int main(void)
{
    t_list *tetros;
    t_tetro tetro1;
    t_tetro tetro2;
    t_tetro tetro3;
    unsigned long long map;
    unsigned long long answer;
    tetros = NULL;
    map = 0;
    answer = 0;
    tetro1.tetro = 52224U;
    tetro1.width = 2;
    tetro1.height = 2;
    tetro1.print = 'A';
    tetro1.used = 0;
    tetro2.tetro = 52224U;
    tetro2.width = 2;
    tetro2.height = 2;
    tetro2.print = 'B';
    tetro2.used = 0;
    tetro3.tetro = 52224u;
    tetro3.width = 2;
    tetro3.height = 2;
    tetro3.print = 'C';
    tetro3.used = 0;
    ft_lstpushfront(&tetro1, &tetros, sizeof(&tetro1));
    ft_lstpushfront(&tetro2, &tetros, sizeof(&tetro2));
    ft_lstpushfront(&tetro3, &tetros, sizeof(&tetro2));
    map = 2315096499073056768U;
    solver(&answer, 3, &tetros);
//    print_tetro_long(answer, 64);
}
/*
int	main(int argc, char *argv[])
{
	t_list *tetros;
	int fd;
	int res;
	size_t count;

	char **test;
	test = initialize_array(6);
	test[0][0] = 'a';
	printf("%s", *test);
	count = 0;
	if (argc != 2)			//do we handle more than 1 file ever??
		return (ft_error("Invalid number of input files"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("File could not be opened"));
	res	= read_input(fd, &tetros, &count);
	if (res != 0)
		return (-1);
	//call solver here
	return (0);
}
*/