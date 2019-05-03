#include "fillit.h"

static char		**initialize_array(size_t size)
{
	char **res;
	size_t i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * size);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = ft_strnew(size);
		i++;
	}
	return (res);
}

static void    fill_array(char **res, size_t mapsize)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (j < mapsize)
    {
        i = 0;
        while (i < mapsize)
        {
            res[j][i] = '.';
            i++;
        }
        j++;
    }
}

static void    put_map(char **res, size_t mapsize)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (j < mapsize)
    {
        i = 0;
        while (i < mapsize)
        {
            ft_putchar(res[j][i]);
            i++;
        }
        ft_putchar('\n');
        j++;
    }
}

static void    place_tetro(t_tetro *t, char **map)
{
    size_t i;
    int x;
    int y;
    uint16_t mask;

    mask = (1U << 15);
    i = 0;
    x = 0;
    y = 0;
//    printf("tetro: %u w: %zu h: %zu x: %u y: %u\n", t->fpt, t->width, t->height, t->x, t->y);
    while (mask)
    {
        if (mask & t->fpt)
        {
            itocoor(&x, &y, i, 4);
            map[y + t->y][x + t->x] = t->print;
        }
        i++;
        mask >>= 1;
    }
}

static void    add_tetros(char **map, t_list **tetros)
{
    t_list *curr;

    curr = *tetros;
    while (curr)
    {
        place_tetro(curr->content, map);
        curr = curr->next;
    }

}

void    print_solution (t_list **tetros, size_t mapsize)
{
    char **res;

    res = initialize_array(mapsize);
    fill_array(res, mapsize);
    add_tetros(res, tetros);
    put_map(res, mapsize);
}