#include "fillit.h"

void    print_map(uint16_t **map)
{
    int i;

    i = 0;
    while (i < 16)
    {
        printf("mp: %u\n", (*map)[i]);
        i++;
    }
}