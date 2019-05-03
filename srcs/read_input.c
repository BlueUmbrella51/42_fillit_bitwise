#include "fillit.h"

int tetro_wh(t_tetro* t, uint16_t mask, uint16_t *visited, uint16_t tetr, size_t index)
{
    uint16_t prev_visited;
    size_t total_size;

    total_size = SIZE * SIZE;
    if ((mask & tetr) != 0 && (*visited & mask) == 0)
    {
        prev_visited = *visited;
        *visited |= mask;
        if (count_ones(visited) == 4 && (prev_visited ^ *visited) == 0)
            return (0);
        if (index < total_size - SIZE && (*visited & (mask << SIZE)) == 0)
            t->height += tetro_wh(t, mask << SIZE, visited, tetr, index + SIZE);
        if (index >= SIZE && (*visited & (mask >> SIZE)) == 0)
            t->height += tetro_wh(t, mask >> SIZE, visited,  tetr, index - SIZE);
        if (index % SIZE != 0 && (*visited & (mask >> 1)) == 0)
            t->width += tetro_wh(t, mask >> 1, visited, tetr, index - 1);
        if ((index + 1) % SIZE != 0 && (*visited & (mask << 1)) == 0)
            t->width += tetro_wh(t, mask << 1, visited, tetr, index + 1);
        return (1);
    }
    return (0);
}

void	find_last(t_list **lst, t_tetro *t)
{
	t_list *tmp;
	t_list *last;

	tmp = *lst;
	while (tmp)
	{	
		if (((t_tetro *)((t_list *)tmp)->content)->type == t->type)
		{
			last = tmp;
			t->last = last;
		}
		tmp = tmp->next;
	}
}

int     find_type(uint16_t tetr, uint16_t *types)
{
    int i;

    i = 0;
    while (i < 19)
    {
        if (types[i] == tetr)
            return (i);
        i++;
    }
    return (999);
}

int		add_tetro(uint16_t tetr, size_t count, t_list **lst)
{
	t_tetro *t;
	size_t index;
	uint16_t mask;
	uint16_t visited;
	uint16_t types[19] = {52224, 27648, 50688, 35904, 19584, 58368, 19968,
    19520, 17984, 35008, 17600, 51328, 50240, 11776, 34952, 36352,
    57856, 59392, 61440};

	t = (t_tetro *)malloc(sizeof(t_tetro));
	if (!t)
		return (0);
	index = find_first(tetr);
	mask = (1U << index);
	visited = 0UL;
	t->type = find_type(tetr, types);
	t->fpt = tetr; 
	t->tetro = convert_sll(tetr);
//	printf("Tetro as uint64: %llu\n", t->tetro);
	t->print = 'A' + (count - 1);
	t->order = count;
	t->last = NULL;
	t->x = 0;
	t->y = 0;
	t->width = 1;
	t->height = 1;
	if (t->type == 0)
	{
		t->width = 2;
		t->height = 2;
	}
	else
		tetro_wh(t, mask, &visited, tetr, index);
	find_last(lst, t);
	if (!(ft_lstaddend(lst, t, sizeof(t_tetro))))
		return (0);
	return (1);
}

int                read_input(int fd, t_list **list, size_t *count)
{
    int test;
    int lr;
    char *line;
    unsigned short dst;
    size_t total_size;

    total_size = SIZE * SIZE;
    lr = 1;
    line = NULL;
    while (lr == 1)
    {
        if (*count > 25)
            return (ft_error("error"));
        test = read_tetromino(&lr, fd, &line, &dst);
        if (test != 1)
            return (test);
        *count += 1;
        if (validate_tetro(&dst, total_size) == 1)
        {
            tetro_translate(&dst, total_size);
            if (!add_tetro(dst, *count, list))
                return (ft_error("error"));
        }
        else
            return(-1);
        dst = 0;
        lr = get_next_line(fd, &line);
        if (lr == 0)
            return (0);
        if (!(line[0] == '\n' || line[0] == '\0'))
            return (ft_error("error"));
    }
    return (0);
}