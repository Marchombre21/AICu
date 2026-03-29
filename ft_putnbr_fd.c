/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:25:32 by aluslu            #+#    #+#             */
/*   Updated: 2026/03/29 13:08:43 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"




static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd((n % 10) + '0', fd);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}