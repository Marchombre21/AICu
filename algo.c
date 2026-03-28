#include "aicu.h"
#include <stdio.h>

int	is_next_heap_winnable(int heap_size)
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


int is_ok_to_take(int nb_to_take)
{
    if (nb_to_take > 3 || nb_to_take < 1)
        return -1;
    return 1;
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
		write(1, "User took 1\n", 10);
	else if (input == 2)
		write(1, "User took 2\n", 10);
	else if (input == 3)
		write(1, "User took 3\n", 10);
}

void	algo_loop(t_vector *vec)
{
    if (!vec || vec->num_elements == 0)
        return;

    size_t i = vec->num_elements - 1;
    int turn;
    int nb_to_take;
    int	str_nb_to_take;

    turn = 1;

    display_heaps(vec);
    while (i > 0)
    {
        i--;
        while (vec->data[i + 1] > 0)
        {
            if (turn == 1)
            {
                if (is_next_heap_winnable(vec->data[i]))
                {
                    if (is_ok_to_take(nb_to_take))
                        nb_to_take = win_move(vec->data[i]);
                }
                else
                    nb_to_take = 1;
                if (is_ok_to_take(nb_to_take))
                    vec->data[i + 1] -= nb_to_take;
					check_input_ia(nb_to_take);
                turn = 0;
            }
            else
            {
                str_nb_to_take = read_user(vec->data[vec->num_elements - 1]);
				if (str_nb_to_take == -1)
					
                if (is_ok_to_take(nb_to_take))
                    vec->data[i + 1] -= nb_to_take;
                check_entry_user(nb_to_take);
                turn = 1;
            }
            display_heaps(vec);
        }
    }
}