#include "../include/ft_printf.h"

int	ft_handle_format(va_list *args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(*args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(*args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(*args, void *));
	else if (format == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	*args_ptr;
	int		len;

	va_start(args, format);
	args_ptr = &args;
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_handle_format(args_ptr, *(format + 1));
			format++;
		}
		else
			len += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	int 	nb = 1243;
	int	len = ft_printf("ft_printf : %p\n", &nb);

	printf("len : %d\n", len);
	printf("prtinf : %p", &nb);
	return (0);
}
