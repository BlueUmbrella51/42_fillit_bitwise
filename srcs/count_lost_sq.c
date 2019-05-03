/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 15:46:05 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/03 17:06:08 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	toggle_bit(size_t index, size_t size, t_field *field)
{
	int x;
	int y;
	unsigned long long tmp;

	itocoor(&x, &y, index, ft_sqrt(size));
	tmp = 9223372036854775808ULL;
	if (y > 7  && x <= 7)
		y -= 8;
	else if (y <= 7 && x > 7)
		x -= 8;
	else if (y > 7 && x > 7)
	{
		y -= 8;
		x -= 8;
	} 
	while (y > 0)
	{
		tmp >>= 8;
		y--;
	}
	while (x > 0)
	{
		tmp >>= 1;
		x--;
	}
	itocoor(&x, &y, index, ft_sqrt(size));
	if (y <= 7 && x <= 7)
		field->top_left = field->top_left ^ tmp;
	else if (y > 7  && x <= 7)
		field->bot_left = field->bot_left ^ tmp;
	else if (y <= 7 && x > 7)
		field->top_right = field->top_right ^ tmp;
	else if (y > 7 && x > 7)
		field->bot_right = field->bot_right ^ tmp;
}

static	int		check_fit_part_field(unsigned long long part_field, unsigned long long tmp)
{
	tmp = tmp ^ part_field;
	part_field = tmp | part_field;
	if (part_field != tmp)
		return (0);
	return (1);
}

static	int		is_zero(size_t index, t_field field)
{
	int x;
	int y;
	unsigned long long tmp;
	int res;

	res = 0;
	itocoor(&x, &y, index, ft_sqrt(field.size));
	tmp = 9223372036854775808ULL;
	if (y > 7  && x <= 7)
		y -= 8;
	else if (y <= 7 && x > 7)
		x -= 8;
	else if (y > 7 && x > 7)
	{
		y -= 8;
		x -= 8;
	} 
	while (y > 0)
	{
		tmp >>= 8;
		y--;
	}
	while (x > 0)
	{
		tmp >>= 1;
		x--;
	}
	itocoor(&x, &y, index, ft_sqrt(field.size));
	if (y <= 7 && x <= 7)
		res = check_fit_part_field(field.top_left, tmp);
	else if (y > 7  && x <= 7)
		res = check_fit_part_field(field.top_left, tmp);
	else if (y <= 7 && x > 7)
		res = check_fit_part_field(field.top_left, tmp);
	else if (y > 7 && x > 7)
		res = check_fit_part_field(field.top_left, tmp);
	return (res);
}

static	size_t	coortoi(int row, int column, size_t size)
{
	size_t index;

	index = 0;
	index = row * size + column;
	return (index);
}

static	size_t	find_next_zero(t_field field, size_t index)
{
	int x;
	int y;
	int res;

	itocoor(&x, &y, index, ft_sqrt(field.size));
	res = 0;    
	if (x > 0)
	{
		res = is_zero(index - 1, field);
		if (res == 1)
			return (index - 1);
	}
	if (x < ft_sqrt(field.size))
	{
		res = is_zero(index + 1, field);
		if (res == 1)
            return (index + 1);
    }
    if (y < ft_sqrt(field.size))
    {
        res = is_zero(coortoi(y + 1, x, ft_sqrt(field.size)), field);
        if (res == 1)
			return (coortoi(y + 1, x, ft_sqrt(field.size)));
	}
	if (y > 0)
 	{
		res = is_zero(coortoi(y - 1, x, ft_sqrt(field.size)), field);
		if (res == 1)
		return (coortoi(y - 1, x, ft_sqrt(field.size)));
    }
	return (0);
}

static	int		check_if_lost(t_field *field, int lost_counter, size_t index)
{
	size_t next;

	toggle_bit(index, field->size, field);
	lost_counter++;
	next = find_next_zero(*field, index);
	while (next != 0)
	{   
		lost_counter = check_if_lost(field, lost_counter, next);
		next = find_next_zero(*field, index);
	}
	return (lost_counter);
}

int				count_lost(t_field field, size_t last_placed)
{
	size_t	index;
	int		lost;
	int		lost_in_path;

	index = 0;
	lost = 0;
	while (index < field.size && index < last_placed)
	{   
		lost_in_path = 0;
		if (is_zero(index, field) == 1)
		{
			lost_in_path = check_if_lost(&field, 0, index);
			if (lost_in_path > 0 && lost_in_path < 4)
				lost = lost + lost_in_path;
		}
		index++;
	}
	if (lost < 0)
		return (0);
	return (lost);
}
