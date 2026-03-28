/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aicu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfitte <bfitte@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:35:48 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/28 15:11:13 by bfitte           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include "vector.h"

int	read_pro_max(t_vector *vec, int fd);
int	store_datas(t_vector *vec, char *datas);


#endif