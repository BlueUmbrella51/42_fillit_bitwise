/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:11:12 by jdunnink       #+#    #+#                */
/*   Updated: 2019/05/06 13:02:12 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>
static int	check_count(size_t *count)
{
	if (*count > 25)
		return (0);
	return (1);
}

static	int		valid_characters(char *line, char f, char e)
{
	size_t i;

	i = 0;
	if (ft_strlen(line) == 21 && line[20] != '\n')
		return (0);
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (line[i] != f && line[i] != e)
				return (0);
		}
		else if (line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int			read_tetri(int fd, size_t *count, uint16_t *dst, t_list **list)
{
	int nbr;
	char buff[22];
	char **tetro;
	size_t total;

	total = SIZE * SIZE;
	nbr = 21;
	tetro = NULL;
	while (nbr >= 20)
	{
		ft_bzero(buff, 22);
		nbr = read(fd, buff, 21);
		printf("%d\n", nbr);
		if (nbr == 0)
			return (1);
		if (nbr < 20)
			return (0);
		if (!check_count(count))
			return (0);
		tetro = ft_strsplit(buff, '\n');
		if (!valid_characters(buff, '#', '.'))
			return (0);
		*dst = 0;
		*count += 1;
		read_tetromino(tetro, dst);
		free_tetro(tetro);
		if (!validate_tetro(dst, total))
			return (0);
		tetro_translate(dst, total);
		if (!add_tetro(*dst, *count, list))
			return (0);
	}
	return (1);
}

int			read_input(int fd, t_list **list, size_t *count)
{
	int 		test;
	uint16_t	dst;

	dst = 0;
	*list = NULL;
	test = read_tetri(fd, count, &dst, list);
	if (!test)
		return (0);
	return (1);
}
