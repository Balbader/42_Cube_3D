/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:17:44 by eloevenb          #+#    #+#             */
/*   Updated: 2023/03/01 17:09:16 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ptrlen(unsigned long ptr)
{
	int				len;
	unsigned long	div;

	len = 1;
	div = 1;
	while ((ptr / div) / 16)
	{
		len++;
		div *= 16;
	}
	return (len);
}

static void	fillptr(unsigned long n, char *str)
{
	if (n / 16 > 0)
		fillptr(n / 16, str + 1);
	if (n % 16 < 10)
		*str = '0' + (n % 16);
	else
		*str = 'a' + (n % 16) - 10;
}

static void	nullptr(char *str)
{
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'i';
	str[3] = 'l';
	str[4] = ')';
}

char	*ft_ptoa(void *ptr)
{
	char	*str;
	int		len;

	if (ptr)
		len = ptrlen((unsigned long) ptr) + 2;
	else
		len = 5;
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (ptr)
	{
		str[0] = '0';
		str[1] = 'x';
		fillptr((unsigned long) ptr, str + 2);
	}
	else
		nullptr(str);
	str[len] = '\0';
	return (str);
}
