/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 08:01:57 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/28 09:19:03 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"
#include "vector.h"

static int	final_check_input(int i, char *nptr)
{
	unsigned int	result;

	result = 0;
	if (!(nptr[i] >= 48 && nptr[i] <= 57))
		return (1);
	while (nptr[i])
	{
		if (!(nptr[i] <= 57 && nptr[i] >= 48))
			return (-1);
		result = (result * 10 + (nptr[i] - 48));
		if (result > 10000)
			return (-1);
		i++;
	}
	return (0);
}

static int	check_input(char *nptr)
{
	int			i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			return (-1);
		i++;
	}
	return (final_check_input(i, nptr));
}

static inline int	parse_content(t_vector *vec, char *buffer)
{
	static	int nb_completed;
	int	i;
	int	start;

	start = i;
	i = 0;
	nb_completed = 0;
	if (vec->max_elements == vec->num_elements)
	{
		if (vector_realloc(vec) == -1)
			return (-1);
	}
	while (buffer[i])
	{
		if (vec->data[i] == '\n')
		{
			if (check_input(vec->data[start] + (i - start)) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}