/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:10:56 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/28 09:48:15 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"
#include "vector.h"

static void	ft_intcpy(void *d, const unsigned int *s, size_t n)
{
	const size_t	chunks = n / 8;
	const size_t	rem = n % 8;
	const uint64_t	*s64 = (const uint64_t *)s;
	uint64_t		*d64;
	unsigned int	*d_uint;
	size_t			i;

	d64 = (uint64_t *)d;
	i = 0;
	while (i < chunks)
	{
		d64[i] = s64[i];
		++i;
	}
	d_uint = (unsigned int *)(d64 + chunks);
	s = (const unsigned int *)(s64 + chunks);
	i = 0;
	while (i < rem)
	{
		d_uint[i] = s[i];
		++i;
	}
}

int	vector_realloc(t_vector *vector)
{
	void	*new_data;

	new_data = malloc(vector->element_size * vector->max_elements * 2);
	if (new_data == NULL)
		return (-1);
	ft_intcpy(new_data, vector->data,
		vector->element_size * vector->num_elements);
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