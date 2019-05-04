/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:11:12 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 14:51:25 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			read_input(int fd, t_list **list, size_t *count)
{
	int				test;
	int				lr;
	char			*line;
	unsigned short	dst;
	size_t			total_size;

	total_size = SIZE * SIZE;
	lr = 1;
	line = NULL;
	while (lr == 1)
	{
		if (*count > 25)
			return (ft_error("error"));
		test = read_tetromino(&lr, fd, &line, &dst);
		if (test != 1)
			return (test);
		*count += 1;
		if (validate_tetro(&dst, total_size) == 1)
		{
			tetro_translate(&dst, total_size);
			if (!add_tetro(dst, *count, list))
				return (ft_error("error"));
		}
		else
			return (-1);
		dst = 0;
		lr = get_next_line(fd, &line);
		if (lr == 0)
			return (0);
		if (!(line[0] == '\n' || line[0] == '\0'))
			return (ft_error("error"));
	}
	return (0);
}
