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

void display_heaps(t_vector *vec)
{
    int i;
    int	j;
	int				k;
	int				diff;
    int             limit;
    int             height_limit;
    int             remaining_heaps = 0;

    i = 0;
	k = 0;
    limit = vec->max;
    height_limit = 8;

    if ((int) vec->num_elements - height_limit > 0)
    {
        remaining_heaps = (int) vec->num_elements - height_limit;
        ft_putstr("remains -> ", 1);
        ft_putnbr_fd(remaining_heaps, 1);
        ft_putstr(" heaps\n", 1);
    }

    while (i < remaining_heaps)
        i++;

    while ((size_t)i < vec->num_elements)
    {
        j = 0;
        k = 0;
        if (vec->data[i] > 100)
        {
            limit = 100;
            vec->max = 100;
        }
        else
            limit = vec->data[i];
		diff = vec->max - limit;
		while (k++ < diff)
			ft_putstr(" ", 1);
        while (j < limit)
        {
            ft_putstr("|", 1);
            if (j != limit)
                ft_putstr(" ", 1);
            j++;
        }
        if (vec->data[i] > 100)
        {
            ft_putstr("remains -> ", 1);
            ft_putnbr_fd(vec->data[i] - limit, 1);
        }
        ft_putstr("\n", 1);
        i++;
    }
}