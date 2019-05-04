/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 12:29:37 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/05/04 12:31:16 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t			min_mapsize(size_t num_tetros)
{
	size_t i;

	i = 2;
	while (i * i < (num_tetros * SIZE))
		i++;
	return (i);
}

static size_t	count_duplicates(int *dups, size_t num_tetros)
{
	size_t i;
	size_t res;

	res = 0;
	i = 0;
	while (i < num_tetros)
	{
		res += dups[i];
		i++;
	}
	return (res);
}

static size_t	count_dup(t_list **lst, size_t num_tetros)
{
	t_list	*curr;
	t_list	*check;
	size_t	i;
	int		dups[num_tetros];

	ft_bzero(dups, num_tetros);
	i = 0;
	if (!*lst)
		return (0);
	curr = (*lst)->next;
	check = *lst;
	while (i < num_tetros && check)
	{
		while (curr)
		{
			if (((t_tetro *)(curr->content))->tetro ==
				((t_tetro *)(check->content))->tetro)
				dups[i] += 1;
			curr = curr->next;
		}
		check = check->next;
		i++;
	}
	return (count_duplicates(dups, num_tetros));
}

static int		get_size(t_list **tetros, size_t num_tetros, uint16_t *map)
{
	size_t	start_size;
	size_t	duplicates;
	int		found;

	found = 0;
	start_size = min_mapsize(num_tetros);
	duplicates = count_dup(tetros, num_tetros);
	if (duplicates < num_tetros / 2 || num_tetros < 6)
		return (start_size);
	while (!find_permutations(*tetros, *tetros, map, start_size, &found))
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		start_size++;
	}
	return (start_size);
}

int				checker(uint16_t *map, t_list **tetros, size_t num_tetros)
{
	size_t min_size;

	min_size = get_size(tetros, num_tetros, map);
	list_sort(*tetros);
	return (min_size);
}
