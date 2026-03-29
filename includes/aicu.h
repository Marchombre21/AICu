/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aicu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:35:48 by bfitte            #+#    #+#             */
/*   Updated: 2026/03/29 13:43:10 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "vector.h"

int		read_pro_max(t_vector *vec, int fd);
int		store_datas(t_vector *vec, char *datas);
int     *get_strategy(t_vector *vec);
int     win_move(int heap_size);
int     lose_move(int heap_size);
int		read_user(int limit);
void	algo_loop(t_vector *vec);
void    ft_putstr(char *s, int fd);
void    display_heaps(t_vector *vec);
void    get_new_max(t_vector *vec);
void	ft_putnbr_fd(int n, int fd);



#endif