#include "aicu.h"


void get_new_max(t_vector *vec)
{
    size_t i;

    i = 0;

    while (i < vec->num_elements)
    {
        if (vec->data[i] > vec->max)
            vec->max = vec->data[i];
        i++;
    }
}

void display_heaps(t_vector *vec, int *strategy)
{
	(void)strategy;
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
        // if (strategy[i] == 0)
        //     ft_putstr("AI wants to win this heap");
        // else
        //     ft_putstr("AI wants to lose this heap");
        write(1, "\n", 1);
        i++;
    }
}