/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 08:01:57 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/28 10:39:45 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"
#include "vector.h"

static int	final_check_input(int i, char *nptr)
{
	unsigned int	result;

	result = 0;
	if (!(nptr[i] >= 48 && nptr[i] <= 57))
		return (-1);
	while (nptr[i])
	{
		if (!(nptr[i] <= 57 && nptr[i] >= 48))
			return (-1);
		result = (result * 10 + (nptr[i] - 48));
		if (result > 10000)
			return (-1);
		i++;
	}
	return (result);
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
	int	res;

	res = 0;
	i = 0;
	start = i;
	nb_completed = 0;
	while (buffer[i])
	{
		if (vec->max_elements == vec->num_elements)
		{
			if (vector_realloc(vec) == -1)
				return (-1);
		}
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			res = check_input(buffer + start);
			if (res == -1)
				return (-1);
			vec->data[vec->num_elements] = res;
			vec->num_elements += 1;
			start = i + 1;
		}
		i++;
	}
	return (1);
}

int	read_pro_max(t_vector *vec)
{
	int	n;
	char	buffer[4096];

	n = 1;
	while (n > 0)
	{
		n = read(0, buffer, 4095);
		if (n == -1)
			return (-1);
		else if (n == 0)
			return (0);
		buffer[n] = 0;
		if (parse_content(vec, buffer) == -1)
			return (-1);
	}
	return (0);
}