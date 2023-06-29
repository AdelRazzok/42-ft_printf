#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_handle_format(va_list *args, const char format);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *ptr);

#endif