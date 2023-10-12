/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:31:09 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:45:12 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char	*us1;
	unsigned const char	*us2;

	us1 = (unsigned const char *) s1;
	us2 = (unsigned const char *) s2;
	i = 0;
	while (i < n && us2[i] && us2[i] == us1[i])
		i++;
	if (i >= n)
		return (0);
	return (us1[i] - us2[i]);
}
