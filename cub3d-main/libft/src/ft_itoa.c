/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:05:44 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:43:48 by eloevenb         ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	abs;
	char			*str;

	len = 0;
	if (n < 0)
	{
		abs = -((unsigned int) n);
		len++;
	}
	else
		abs = (unsigned int) n;
	len += ft_int_length(abs);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	ft_fill_str(str, abs, len - 1);
	str[len] = '\0';
	return (str);
}
