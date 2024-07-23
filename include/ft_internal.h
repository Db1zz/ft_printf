/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:54:30 by gonische          #+#    #+#             */
/*   Updated: 2024/07/22 18:09:49 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERNAL_H
# define FT_INTERNAL_H

/*
	Headers
*/
#include "../libft/libft.h"
#include "./ft_printf.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>

/*
	Preprocessor definitions
*/
#define MAX_BUFFER_SIZE 32
#define MINUS_FLAG 		1
#define ZERO_FLAG 		1 << 1
#define DOT_FLAG		1 << 2
#define HASH_FLAG		1 << 3
#define SPACE_FLAG		1 << 4
#define PLUS_FLAG		1 << 5
#define WIDTH_FLAG		1 << 6

#define PATTERN_SIZE 6

/*
	Data type defenitions
*/
typedef struct _format
{
	char	specifier;
	char	flags;
	int		width;
	int		precision;
	int		size;
	char	*output_str;
	char	*special_str;
} s_format;

typedef	int (*disp_func)(s_format *);

/*
	Functions
*/
void		*ft_calloc(size_t count, size_t size);
void		ft_set_bit(char *bit_set, char bit);
bool		ft_check_bit(char bit_set, char bit);
bool		ft_check_remove_bit(char *bit_set, char bit);
void		ft_adjust_bits(char *bit_set, char bits);
bool		ft_isspecifier(char c);
char		ft_isflag(char c);
void		ft_calc_width_precision(s_format *f);
void		ft_validate_flags(s_format *f);
size_t		ft_get_number_size(int64_t number);
void		ft_convert_to_address_str(s_format *f, uint64_t address);
void		ft_convert_to_number_str(s_format *f, int64_t number);
void		ft_convert_to_hex_str(s_format *f, uint32_t number);
void		ft_get_specifier(const char *str, s_format *f);
void		ft_get_special_str(s_format *f);
void		ft_get_output_str(va_list *data, s_format *f);
void		ft_get_flags(const char *str, s_format *f);
s_format	*ft_get_format_data(const char *str, va_list *data);
int			ft_display_padding(s_format *f);
int			ft_display_modifier(s_format *f);
int			ft_display_precision(s_format *f);
int			ft_display_str(s_format *f);
int			ft_display_format(s_format *f);
void		ft_calc_width_precision(s_format *f);
void		ft_validate_flags(s_format *f);
size_t		ft_get_number_size(int64_t number);
disp_func 	*ft_get_pattern(s_format *f);
int			ft_printstr(char *str);

#endif // FT_INTERNAL_H