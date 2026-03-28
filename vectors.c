/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:10:56 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/28 11:26:40 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"
#include "vector.h"

static void ft_intcpy(unsigned int *d, const unsigned int *s, size_t n)
{
	const size_t	chunks = n / 2;
	const size_t	rem = n % 2;
	const uint64_t	*s64 = (const uint64_t *)s;
	uint64_t		*d64 = (uint64_t *)d;
	size_t			i;

	i = 0;
	while (i < chunks)
	{
		d64[i] = s64[i];
		++i;
	}

	// The remain of a division by 2 is either 1 or 0.
	if (rem)
		d[n - 1] = s[n - 1];
}

int	vector_realloc(t_vector *vector)
{
	void	*new_data;

	new_data = malloc(vector->element_size * vector->max_elements * 2);
	if (new_data == NULL)
		return (-1);
	ft_intcpy(new_data, vector->data, vector->num_elements);
	free(vector->data);
	vector->data = new_data;
	vector->max_elements *= 2;
	return (0);
}

int	vector_init(t_vector *vector, size_t default_size)
{
	vector->element_size = sizeof(unsigned int);
	vector->max_elements = default_size;
	vector->num_elements = 0;
	vector->data = malloc(sizeof(unsigned int) * default_size);
	if (vector->data == NULL)
		return (-1);
	return (0);
}