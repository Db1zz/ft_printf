/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:19:35 by gonische          #+#    #+#             */
/*   Updated: 2024/07/21 19:23:51 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_internal.h"

void	ft_calc_width_precision(s_format *f)
{
	int	output_size;

	output_size = ft_strlen(f->output_str);
	if (f->specifier == 's')
	{
		if (output_size >= f->precision && ft_check_bit(f->flags, DOT_FLAG))
			f->width -= f->precision;
		else
			f->width -= output_size;
	}
	else
	{
		f->precision -= output_size;
		f->width -= (ft_strlen(f->special_str) + output_size);
		if (f->precision > 0)
			f->width -= f->precision;
	}
}

void	ft_validate_flags(s_format *f)
{
	const char flags[][2] = {
		{'c', MINUS_FLAG | WIDTH_FLAG},
		{'%', MINUS_FLAG | WIDTH_FLAG},
		{'p', MINUS_FLAG | WIDTH_FLAG},
		{'s', MINUS_FLAG | WIDTH_FLAG | DOT_FLAG},
		{'d', MINUS_FLAG | WIDTH_FLAG | DOT_FLAG | ZERO_FLAG | SPACE_FLAG | PLUS_FLAG},
		{'i', MINUS_FLAG | WIDTH_FLAG | DOT_FLAG | ZERO_FLAG | SPACE_FLAG | PLUS_FLAG},
		{'u', MINUS_FLAG | ZERO_FLAG | WIDTH_FLAG | DOT_FLAG},
		{'x', MINUS_FLAG | ZERO_FLAG | HASH_FLAG | WIDTH_FLAG | DOT_FLAG},
		{'X', MINUS_FLAG | ZERO_FLAG | HASH_FLAG | WIDTH_FLAG | DOT_FLAG}};
	int	i;

	i = 0;
	while (flags[i] && flags[i][0] != f->specifier)
		i++;
	if (flags[i][0] == f->specifier)
		ft_adjust_bits(&f->flags, flags[i][1]);
}

size_t	ft_get_number_size(int64_t number)
{
	size_t		result;
	uint64_t	num;

	result = 1;
	if (number < 0)
		num = number * -1;
	else
		num = number;
	while (num > 9)
	{
		num /= 10;
		result++;
	}
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	
	if (!(result = malloc(count * size)))
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}
