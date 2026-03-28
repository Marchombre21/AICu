#include "aicu.h"
#include <stdio.h>

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


void get_new_max(t_vector *vec)
{
    size_t i;

    i = 0;

    while (i < vec->num_elements)
    {
        if (vec->data[i] > (size_t) vec->max)
            vec->max = vec->data[i];
        i++;
    }
}

void display_heaps(t_vector *vec)
{
    size_t i;
    unsigned int	j;
	int				k;
	int				diff;

    i = 0;
	k = 0;
    while (i < vec->num_elements)
    {
        j = 0;
        k = 0;
		diff = vec->max - vec->data[i];
		while (k++ < diff)
			write(1, " ", 1);
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

void	check_input_ia(int input)
{
	if (input == 1)
		write(1, "AI took 1\n", 10);
	else if (input == 2)
		write(1, "AI took 2\n", 10);
	else if (input == 3)
		write(1, "AI took 3\n", 10);
}

void	check_entry_user(int input)
{
	if (input == 1)
		write(1, "User took 1\n", 12);
	else if (input == 2)
		write(1, "User took 2\n", 12);
	else if (input == 3)
		write(1, "User took 3\n", 12);
}

void algo_loop(t_vector *vec)
{
    if (!vec || vec->num_elements == 0)
        return;

    int i = vec->num_elements - 1;
    int turn = 1;
    int nb_to_take;

    display_heaps(vec);
    while (i >= 0)
    {
        while (vec->data[i] > 0)
        {
            if (turn == 1)
            {
                if (i > 0 && is_next_heap_winnable(vec->data[i - 1]))
                    nb_to_take = win_move(vec->data[i]);
                else
                    nb_to_take = 1;
                
                vec->data[i] -= nb_to_take;
                check_input_ia(nb_to_take);
                turn = 0;
            }
            else
            {
                ft_putstr("Please choose between 1 and 3 items\n");
                nb_to_take = read_user(vec->data[i]);
                if (nb_to_take == -1)
                    continue ;
                
                vec->data[i] -= nb_to_take;
                check_entry_user(nb_to_take);
                turn = 1;
            }
            get_new_max(vec);
            display_heaps(vec);
        }
        i--;
    }
    if (turn == 0)
        write(1, "You are the winner!\n", 20);
    else
        write(1, "AI is the winner!\n", 18);
}