#include "fillit.h"

size_t			min_mapsize(size_t num_tetros)
{
	size_t i;

	i = 2;
	while (i * i < (num_tetros * SIZE))
		i++;
	return (i);
}