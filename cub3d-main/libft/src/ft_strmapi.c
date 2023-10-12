/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:35:29 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:45:09 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*mapped;
	unsigned int	i;

	len = (unsigned int) ft_strlen(s);
	mapped = (char *) malloc((len + 1) * sizeof(char));
	if (!mapped)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mapped[i] = (*f)(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
