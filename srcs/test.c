#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <strings.h>

size_t  get_row(size_t index, int o_size)
{
    size_t row;

    row = 0;
    row = 3 - (index / o_size);
//    printf("row: %zu\n", row);
    return (row);
}

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

int main()
{
    uint16_t *map;
    uint16_t tetro;
    uint16_t tetro2;
    uint64_t t;
    unsigned char x;
    uint64_t t2;

    x = 1;
    tetro2 = 17600;
    tetro = 51328;
    t = convert_sll(tetro);
    t2 = convert_sll(tetro2);
//    printf("tetro: %lu\n %lu\n", t, t2);
    map = (uint16_t *)malloc(sizeof(uint16_t) * 16);
    bzero(map, sizeof(uint16_t) * 16);
    *((uint64_t *)(map)) ^= t;
    *((uint64_t *)(map)) ^= t;
    *((uint64_t *)(map)) ^= t2 >> x;

/*    for (int i = 0; i < 16; i++)
    {
        printf("%u\n", map[i]);
    }
*/}
