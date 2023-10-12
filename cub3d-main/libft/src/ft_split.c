/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:35:55 by eloevenb          #+#    #+#             */
/*   Updated: 2022/11/18 17:44:45 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_nb_strs(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (!s[i + 1] || s[i + 1] == c))
			nb++;
		i++;
	}
	return (nb);
}

int	ft_wlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_free_strs(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		wlen;
	int		i;

	i = ft_nb_strs(s, c);
	strs = (char **) malloc((i + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			wlen = ft_wlen(s, c);
			strs[i] = ft_substr(s, 0, wlen);
			if (!strs[i])
				return (ft_free_strs(strs, i));
			s += wlen - 1;
			i++;
		}
		s++;
	}
	strs[i] = 0;
	return (strs);
}
