#include "aicu.h"


static void	check_input_ia(int input)
{
	if (input == 1)
		write(1, "AI took 1\n", 10);
	else if (input == 2)
		write(1, "AI took 2\n", 10);
	else if (input == 3)
		write(1, "AI took 3\n", 10);
}

static void	check_entry_user(int input)
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
    int *strategy;
    int i;
    int turn;
    int nb_to_take;

    if (!vec || vec->num_elements == 0)
        return;

    strategy = get_strategy(vec);
    if (!strategy)
        return;

    i = vec->num_elements - 1;
    turn = 1;

    display_heaps(vec, strategy);
    while (i >= 0)
    {
        while (vec->data[i] > 0)
        {
            if (turn == 1)
            {
                if (strategy[i] == 0)
                    nb_to_take = win_move(vec->data[i]);
                else
                    nb_to_take = lose_move(vec->data[i]);
                
                vec->data[i] -= nb_to_take;
                check_input_ia(nb_to_take);
                turn = 0;
            }
            else
            {
                ft_putstr("Please choose between 1 and 3 items\n");
                nb_to_take = read_user(vec->data[i]);
                if (nb_to_take == -1)
                    continue;
                
                vec->data[i] -= nb_to_take;
                check_entry_user(nb_to_take);
                turn = 1;
            }
            get_new_max(vec);
            display_heaps(vec, strategy);
        }
        i--;
    }
    free(strategy);

    if (turn == 0)
        write(1, "You are the winner!\n", 20);
    else
        write(1, "AI is the winner!\n", 18);
}