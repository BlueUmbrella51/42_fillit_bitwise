#include "fillit.h"

int	count_ones(uint16_t *tetro)
{
	uint16_t tmp;
	int count;

	count = 0;
	tmp = *tetro;
	while (tmp)
	{
		count += tmp & 1;
		tmp >>= 1U;
	}
	return (count);
}
