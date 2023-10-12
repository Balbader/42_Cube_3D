/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:17:09 by eloevenb          #+#    #+#             */
/*   Updated: 2023/03/01 16:25:28 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	hexlen(unsigned int n)
{
	int				len;
	unsigned int	div;

	len = 1;
	div = 1;
	while ((n / div) / 16)
	{
		len++;
		div *= 16;
	}
	return (len);
}

static void	fillhex(unsigned int n, char *str, int caps)
{
	if (n / 16 > 0)
		fillhex(n / 16, str + 1, caps);
	if (n % 16 < 10)
		*str = '0' + (n % 16);
	else
	{
		if (caps)
			*str = 'A' + (n % 16) - 10;
		else
			*str = 'a' + (n % 16) - 10;
	}
}

char	*ft_xtoa(int hex, int caps)
{
	char	*str;
	int		len;
	int		i;

	len = hexlen((unsigned int) hex);
	if (hex)
		len += 2;
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (hex)
	{
		str[0] = '0';
		str[1] = 'x' + caps * ('X' - 'x');
		i = 2;
	}
	fillhex((unsigned int) hex, str + i, caps);
	str[len] = '\0';
	return (str);
}
