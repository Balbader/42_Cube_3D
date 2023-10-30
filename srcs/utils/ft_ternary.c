/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:40:53 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 15:40:55 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Function for a ternaire
 *
 * @param cond for the conditions
 * @param valid_1 if cond is true return valid_1
 * @param valid_2 if cond is false return valid_2
 *
 * @return void* the value of valid_1 or valid_2
 */

void	*ft_ternary(int const cond, void *valid_1, void *valid_2)
{
	if (cond)
		return (valid_1);
	return (valid_2);
}
