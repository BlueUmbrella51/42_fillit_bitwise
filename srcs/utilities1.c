#include "fillit.h"

size_t  get_row(size_t index, int o_size)
{
    size_t row;

    row = 0;
    row = 3 - (index / o_size);
//    printf("row: %zu\n", row);
    return (row);
}

void    coortoi(size_t *index, int x, int y, size_t width)
{
    *index = x + y * width;
}

void	itocoor(int *x, int *y, size_t index, size_t size)
{
	*x = index % size;
	*y = index / size;
}

//only works to bigger sizes
size_t    convert_index(size_t index, size_t o_size, size_t n_width)
{
    size_t row;
    size_t conv;

    row = get_row(index, o_size);
	if (row != 0)
        conv = (n_width * row) + (index % o_size);
	else
		conv = index * 16;
    return (conv);
}

uint64_t convert_sll(uint16_t t)
{
    uint64_t res;
    uint16_t mask;
    uint64_t add;
    size_t i;
    size_t index;

    i = 0;
    mask = (1U << 15);
    add = 1ULL;
    res = 0ULL;
    while (mask)
    {
        if (mask & t)
        {
            index = convert_index(i, 4, 16);
            add = (1ULL << (63 - index));
            res |= add;
        }
        mask >>= 1;
        i++;
    }
    return (res);
}
