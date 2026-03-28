/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:08:49 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/28 18:42:14 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

typedef struct s_vector
{
	size_t	element_size;
	size_t	num_elements;
	size_t	max_elements;
	int		max;
	char	*remain;
	unsigned int	*data;
}				t_vector;

int		vector_realloc(t_vector *vector);
int		vector_init(t_vector *vector, size_t default_size);

#endif