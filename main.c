/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:06:19 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/28 11:28:25 by bfitte           ###   ########lyon.fr   */
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
	read_pro_max(&vec);
	i = 0;
	while (i < vec.num_elements)
	{
		printf("%u\n", vec.data[i]);
		i++;
	}
	free(vec.data);
	
	return (0);
}