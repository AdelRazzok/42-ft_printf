/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:11:06 by arazzok           #+#    #+#             */
/*   Updated: 2023/08/17 13:38:23 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_handle_format(va_list *args, const char format);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(uintptr_t ptr);
int	ft_print_nbr(int nbr);
int	ft_print_uint(unsigned int nbr);
int	ft_print_hexa(unsigned int nb, const char format);

#endif