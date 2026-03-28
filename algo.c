#include "aicu.h"

void ft_putstr(char *s)
{
    size_t i;

    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
}

int is_next_heap_winnable(int heap_size)
{
    if (heap_size % 4 != 1)
        return 1;
    return 0;
}

int win_move(int heap_size)
{
    int i;
    int new_heap_size;

    i = 1;
    while (i <= 3)
    {
        new_heap_size = heap_size - i;
        if (new_heap_size >= 0 && new_heap_size % 4 == 1)
            return i;
        i++;
    }
    return 1;
}


int is_ok_to_take(int nb_to_take, int heap_size)
{
    if (nb_to_take > 3 || nb_to_take < 1)
        return 0;
    if (heap_size - nb_to_take < 0)
        return 0;
    return 1;
}

void display_heaps(t_vector *vec)
{
    size_t i;
    unsigned int j;

    i = 0;
    while (i < vec->num_elements)
    {
        j = 0;
        while (j < vec->data[i])
        {
            write(1, "|", 1);
            if (j != vec->data[i])
                write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

void    algo_loop(t_vector *vec)
{
    if (!vec || vec->num_elements == 0)
        return;

    size_t i = vec->num_elements - 1;
    int turn;
    int nb_to_take;
    char *str_nb_to_take;

    turn = 1;

    display_heaps(vec);
    while (i >= 0)
    {
        i--;
        while (vec->data[i + 1] > 0)
        {
            printf("heap size-> %d\n", vec->data[i + 1]);
            if (turn == 1)
            {
                if (is_next_heap_winnable(vec->data[i]))
                {
                    if (is_ok_to_take(nb_to_take, vec->data[i + 1]))
                        nb_to_take = win_move(vec->data[i + 1]);
                }
                else
                    nb_to_take = 1;
                if (is_ok_to_take(nb_to_take, vec->data[i + 1]))
                    vec->data[i + 1] -= nb_to_take;
                printf("AI takes %d\n", nb_to_take);
                turn = 0;
            }
            else
            {
                printf("Please choose between 1 and 3\n");
                str_nb_to_take = get_next_line(0);
                nb_to_take = ft_atoi(str_nb_to_take);
                if (is_ok_to_take(nb_to_take, vec->data[i + 1]))
                {
                    vec->data[i + 1] -= nb_to_take;
                    printf("User takes %d\n", nb_to_take);
                    turn = 1;
                }
                else
                    printf("%d - Invalid choice\n", nb_to_take);
                // printf("%s", str_nb_to_take);
                free(str_nb_to_take);
            }
            display_heaps(vec);
        }
    }
}