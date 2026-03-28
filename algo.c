
#include "vector.h"

int is_next_heap_winnable(int heap_size)
{
    if (heap_size % 4 != 1)
        return 1;
    return -1;
}


int win_move(int heap_size)
{
    size_t i;
    int new_heap_size;

    i = 1;
    new_heap_size = heap_size;
    while (i <= 3)
    {
        new_heap_size = heap_size - i;
        if (new_heap_size % 4 == 1)
            return i;
    }
    return -1;
}


int is_heap_empty(int heap_size)
{
    if (heap_size == 0)
        return 1;
    return -1;
}

void    algo_loop(t_vector *vec)
{
    size_t i;
    int nb_to_take;

    i = vec->num_elements - 2;
    nb_to_take = 0;
    while (i >= 0)
    {
        if (is_next_heap_winnable(vec->data[i]))
        {
            nb_to_take = win_move(vec->data[i]);
        }
        else
        {

        }
    }
}