/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:15:39 by gonische          #+#    #+#             */
/*   Updated: 2024/07/22 13:21:06 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_internal.h"

void	ft_convert_to_address_str(s_format *f, u_int64_t address)
{
	const char	*hex_digits = "0123456789abcdef";
	int	i;

	i = 8;
	if (address == 0)
		f->output_str[2] = '0';
	else
	{
		while (address > 0)
		{
			f->output_str[i--] = hex_digits[address % 16];
			address /= 16;
		}
	}
	f->special_str[0] = '0';
	f->special_str[1] = 'x';
}

void	ft_convert_to_number_str(s_format *f, int64_t number)
{
	int			i;
	u_int32_t	num;

	i = (int)ft_get_number_size(number);
	if (number < 0)
	{
		f->special_str[0] = '-';
		num = number * -1;
	}
	else
		num = number;
	if (num == 0)
		f->output_str[0] = '0';
	while (num)
	{
		f->output_str[--i] = (num % 10) + '0';
		num /= 10;
	}
}

void	ft_convert_to_hex_str(s_format *f, u_int32_t number)
{
	const char	*hex_digits = "0123456789abcdef";
	int			modifier;
	int			i;
	char		digit;
	uint32_t	temp;

	modifier = 0;
	if (f->specifier == 'X')
		modifier = 'a' - 'A';
	i = 0;
	temp = number;
	while (temp /= 16)
		i++;
	while (i >= 0)
	{
		digit = hex_digits[number % 16];
		if (digit >= 'a')
			digit -= modifier;
		f->output_str[i--] = digit;
		number /= 16;
	}
}
