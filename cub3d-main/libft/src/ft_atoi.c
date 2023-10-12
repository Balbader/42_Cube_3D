/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:01 by eloevenb          #+#    #+#             */
/*   Updated: 2023/04/04 14:35:47 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned int	res;

	sign = 1;
	while (ft_isspace((int) *nptr))
		nptr++;
	while (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign *= -1;
	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int) res * sign);
}
