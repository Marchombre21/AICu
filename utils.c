/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:22:34 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/28 09:19:47 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"
#include "vector.h"
#include <stdint.h>

void	ft_intcpy(unsigned int *d, const unsigned int *s, size_t n)
{
	const size_t	chunks = n / 8;
	const size_t	rem = n % 8;
	const uint64_t	*s64 = (const uint64_t *)s;
	uint64_t		*d64;
	size_t			i;

	d64 = (uint64_t *)d;
	i = 0;
	while (i < chunks)
	{
		d64[i] = s64[i];
		++i;
	}
	d = (char *)(d64 + chunks);
	s = (const char *)(s64 + chunks);
	i = 0;
	while (i < rem)
	{
		d[i] = s[i];
		++i;
	}
}

int	read_pro_max(t_vector *vec)
{
	unsigned int	n;
	char	buffer[4096];

	n = 1;
	while (n > 0)
	{
		// if (vec->max_elements - vec->num_elements < 10000)
		// {
		// 	if (vector_realloc(vec) == -1)
		// 		return (-1);
		// }
		n = read(0, buffer, 4095);
		if (n == -1)
			return (-1);
		else if (n == 0)
			return (0);
		buffer[n] = 0;
		// vec->num_elements += n;
		if (parse_content(vec, buffer) == -1)
			return (-1);
	}
	return (0);
}