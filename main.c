/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:06:19 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/28 13:51:30 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "aicu.h"
#include <stdio.h>

int	main(void)
{
	t_vector	vec;
	size_t	i;

	vector_init(&vec, 50);
	if (read_pro_max(&vec) == -1)
	{
		printf("%i", vec.data[vec.num_elements - 1]);
		return (1);
	}
	i = 0;
	printf("%zu", vec.num_elements);
	while (i < vec.num_elements)
	{
		printf("%u\n", vec.data[i]);
		i++;
	}
	free(vec.data);
	
	return (0);
}