/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:31:21 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/07 16:31:22 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_read_map_row(t_world *world, char *ptr)
{
	char	*tmp;

	ft_check_world(world);
	ptr = ft_trim(ptr);
	if (!world->raw_map)
		world->raw_map = ft_strdup(ptr);
	else
	{
		tmp = world->raw_map;
		world->raw_map = ft_strjoin(world->raw_map, ptr);
		free(tmp);
	}
	tmp = world->raw_map;
	world->raw_map = ft_strjoin(world->raw_map, "\n");
	free(tmp);
}
