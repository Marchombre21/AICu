/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 08:01:57 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/28 08:07:11 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"
#include "vector.h"

static inline void	come_back(t_vector *vec, size_t *parse_cursor)
{
	--(*parse_cursor);
	while (*parse_cursor > 0 && vec->data[*parse_cursor])
		--(*parse_cursor);
	if (!vec->data[*parse_cursor])
		++(*parse_cursor);
	return ;
}

static inline void	parse_content(t_vector *vec, size_t *parse_cursor)
{
	static uint32_t	wordpos = UINT32_MAX;
	static uint8_t	is_key = 1;

	while (*parse_cursor < vec->num_elements)
	{
		if (!vec->data[*parse_cursor])
			return (come_back(vec, parse_cursor));
		else if (vec->data[*parse_cursor] == '\n')
		{
			vec->data[*parse_cursor] = 0;
			wordpos = UINT32_MAX;
		}
		else if (wordpos == UINT32_MAX)
			wordpos = *parse_cursor;
		++(*parse_cursor);
	}
}