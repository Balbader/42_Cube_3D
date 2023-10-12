/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloevenb <eloevenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:14:53 by eloevenb          #+#    #+#             */
/*   Updated: 2023/03/01 17:08:55 by eloevenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		put_strings_fd(t_list *strings, int fd);
int		ft_convert(va_list *args, const char *format, t_list **strings);
size_t	append_substring(const char *format, t_list **strings);
int		size_sum(t_list *strings);

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list		args;
	t_list		*strings;
	int			i;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	strings = NULL;
	while (format[i])
	{
		if (format[i] != '%')
			i += append_substring(format + i, &strings);
		else
			i += ft_convert(&args, format + i, &strings);
	}
	i = put_strings_fd(strings, fd);
	ft_lstclear(&strings, &free);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_list		*strings;
	int			i;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	strings = NULL;
	while (format[i])
	{
		if (format[i] != '%')
			i += append_substring(format + i, &strings);
		else
			i += ft_convert(&args, format + i, &strings);
	}
	i = put_strings_fd(strings, STDIN_FILENO);
	ft_lstclear(&strings, &free);
	return (i);
}
