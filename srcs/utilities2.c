#include "fillit.h"

int		ft_error(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	ft_putchar('\n');
	return (-1);
}

int count_ones(uint16_t *tetro)
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

size_t find_first(uint16_t tetro)
{
    uint16_t mask;
    size_t i;

    i = 0;
    mask = 1U;
    while ((mask & tetro) == 0)
    {
        mask = (mask << 1U);
        i++;
    }
    return(i);
}

void    print_tetro(t_list *curr)
{
    t_tetro *t;
    uint64_t  mask;
    int count;

    mask = (1ULL << 63);
    count = 64;
    t = curr->content;
    while (mask)
    {
        if (count % 16 == 0)
            printf("\n");
        if (mask & t->tetro)
            printf("#");
        if ((mask & t->tetro) == 0)
            printf(".");
        mask >>= 1ULL;
        count--;
    }
    printf("\n");
}

void    print_us(uint16_t *map)
{
    int i;
    uint16_t mask;
    int j;

    j = 0;
    i = 0;
    while (i < 16)
    {
        mask = (1U << 15);
        j = 0;
        while (j < 16)
        {
             if (map[i] & mask)
                printf("#");
             else
                printf(".");
            mask >>= 1;
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
}

void    print_lst(t_list **lst)
{
    t_list *curr;

    curr = *lst;
    while (curr)
    {
        printf("%llu\n", ((t_tetro *)((t_list *)curr)->content)->tetro);
        curr = curr->next;
    }
    printf("\n");
}
