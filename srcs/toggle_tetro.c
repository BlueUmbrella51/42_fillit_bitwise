#include "fillit.h"

void    toggle_tetro(uint16_t *map, t_tetro *tetro)
{
    *(uint64_t *)(map + tetro->y) ^= (tetro->tetro >> tetro->x);
}
