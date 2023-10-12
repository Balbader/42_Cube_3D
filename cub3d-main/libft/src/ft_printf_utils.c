/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:41:32 by eloevenb          #+#    #+#             */
/*   Updated: 2023/03/01 17:09:38 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	size_sum(t_list *strings)
{
	int	size;

	size = 0;
	while (strings)
	{
		size += (int) ft_strlen((char *) strings->content);
		strings = strings->next;
	}
	return (size);
}

size_t	append_substring(const char *format, t_list **strings)
{
	char	*end;
	size_t	size;
	t_list	*new;

	end = ft_strchr(format, '%');
	if (!end)
		size = ft_strlen(format);
	else
		size = (size_t)(end - format);
	new = ft_lstnew(ft_substr(format, 0, size));
	if (!new)
		return (0);
	ft_lstadd_back(strings, new);
	return (size);
}

int	ft_convert(va_list *args, const char *format, t_list **strings)
{
	if (format[1] == '%')
		ft_lstadd_back(strings, ft_lstnew(ft_ctoa('%')));
	else if (format[1] == 'c')
		ft_lstadd_back(strings, ft_lstnew(ft_ctoa(va_arg(*args, int))));
	else if (format[1] == 's')
		ft_lstadd_back(strings, ft_lstnew(ft_strdup(va_arg(*args, char *))));
	else if (format[1] == 'i' || format[1] == 'd')
		ft_lstadd_back(strings, ft_lstnew(ft_itoa(va_arg(*args, int))));
	else if (format[1] == 'u')
		ft_lstadd_back(strings, \
		ft_lstnew(ft_utoa(va_arg(*args, unsigned int))));
	else if (format[1] == 'x')
		ft_lstadd_back(strings, ft_lstnew(ft_xtoa(va_arg(*args, int), 0)));
	else if (format[1] == 'X')
		ft_lstadd_back(strings, ft_lstnew(ft_xtoa(va_arg(*args, int), 1)));
	else if (format[1] == 'p')
		ft_lstadd_back(strings, ft_lstnew(ft_ptoa(va_arg(*args, void *))));
	else
		return (1);
	return (2);
}

void	fill_cat(t_list *strings, char *cat)
{
	int		i;
	int		j;
	t_list	*iter;

	i = 0;
	iter = strings;
	while (iter)
	{
		j = 0;
		while (((char *) iter->content)[j])
		{
			cat[i] = ((char *) iter->content)[j];
			j++;
			i++;
		}
		iter = iter->next;
	}
	cat[i] = '\0';
}

int	put_strings_fd(t_list *strings, int fd)
{
	char	*cat;
	int		size;

	size = size_sum(strings);
	cat = (char *) malloc((size + 1) * sizeof(char));
	if (cat)
	{
		fill_cat(strings, cat);
		ft_putstr_fd(cat, fd);
		free(cat);
	}
	return (size);
}
