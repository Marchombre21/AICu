#include "aicu.h"



void ft_putstr(char *s, int fd)
{
    size_t i;

    i = 0;
    while (s[i])
		i++;
	write(fd, s, i);
}


int win_move(int heap_size)
{
    int i;
    int new_heap_size;

    i = 1;
    while (i <= 3)
    {
        new_heap_size = heap_size - i;
        if (new_heap_size > 0 && new_heap_size % 4 == 1)
            return i;
        i++;
    }
    return 1;
}

int lose_move(int heap_size)
{
    int i;
    int new_heap_size;

    i = 1;
    while (i <= 3)
    {
        new_heap_size = heap_size -i;
        if (new_heap_size >= 0 && new_heap_size % 4 == 0)
            return i;
        i++;
    }
    if (heap_size >= 3)
        return (3);
    return (heap_size);
}



int *get_strategy(t_vector *vec)
{
    int *strategy;
    int is_winning_pos;
    size_t i;

    strategy = malloc(sizeof(int) * vec->num_elements);
    if (!strategy)
        return (NULL);

    strategy[0] = 0;
    is_winning_pos = (vec->data[0] % 4 != 1);

    i = 1;
    while (i < vec->num_elements)
    {
        if (is_winning_pos)
        {
            strategy[i] = 0;
            is_winning_pos = (vec->data[i] % 4 != 1);
        }
        else
        {
            strategy[i] = 1;
            is_winning_pos = (vec->data[i] % 4 != 0);
        }
        i++;
    }
    return (strategy);
}