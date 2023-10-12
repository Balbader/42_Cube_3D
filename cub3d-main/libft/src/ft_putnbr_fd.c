/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:58:02 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:44:38 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_putabs_fd(unsigned int n, int fd)
{
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs;

	if (n < 0)
	{
		abs = -((unsigned int) n);
		ft_putchar_fd('-', fd);
	}
	else
		abs = (unsigned int) n;
	ft_putabs_fd(abs, fd);
}
