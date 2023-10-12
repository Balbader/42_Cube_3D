/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:30:51 by eloevenb          #+#    #+#             */
/*   Updated: 2023/02/28 21:34:47 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned int	ft_int_length(unsigned int n)
{
	unsigned int	len;
	unsigned int	pow;

	len = 1;
	pow = 1;
	while ((n / 10) / pow > 0)
	{
		pow *= 10;
		len++;
	}
	return (len);
}

static void	ft_fill_str(char *str, unsigned int abs, int i)
{
	if (abs / 10 > 0)
		ft_fill_str(str, abs / 10, i - 1);
	str[i] = abs % 10 + '0';
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	len;
	char			*str;

	len = 0;
	len += ft_int_length(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_fill_str(str, n, len - 1);
	str[len] = '\0';
	return (str);
}
