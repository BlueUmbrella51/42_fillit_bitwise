/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:11:12 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 15:57:36 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			read_input(int fd, t_list **list, size_t *count)
{
	int				lr;
	char			*line;
	unsigned short	dst;

	lr = 1;
	while (lr == 1)
	{
		if (*count > 25)
			return (ft_error("error"));
		if (read_tetromino(&lr, fd, &line, &dst) < 1)
		   break ;
		*count += 1;
		if (validate_tetro(&dst, SIZE * SIZE) == 1)
		{
			tetro_translate(&dst, SIZE * SIZE);
			if (!add_tetro(dst, *count, list))
				return (ft_error("error"));
		}
		else
			return (-1);
		dst = 0;
		if (get_next_line(fd, &line) == 0)
			return (0);
	}
	return (-1);
}
