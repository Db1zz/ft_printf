/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:53:19 by gonische          #+#    #+#             */
/*   Updated: 2024/07/23 19:49:19 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_internal.h"

int	ft_get_hex_size(uint64_t hex)
{
	int	i;

	i = 1;
	while (hex / 16)
	{
		hex /= 16;
		i++;
	}
	return (i);
}
