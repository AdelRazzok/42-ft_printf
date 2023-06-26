#include "../include/ft_printf.h"

int	ft_handle_format(va_list *args_ptr, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(*args_ptr, int));
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
	int len = ft_printf("test est %c %c aeifjae %c\n", 'a', 'b', 'c');
	printf("printf len : %d\n", len);
	return (0);
}
