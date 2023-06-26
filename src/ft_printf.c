#include "../include/ft_printf.h"

int	ft_handle_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (format == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_handle_format(args, *(format + 1));
			format++;
		}
		else
			len += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (len);
}

// int	ft_printf(const char *str, ...)
// {
// 	int		i;
// 	int		len;
// 	va_list	args;

// 	i = 0;
// 	len = 0;
// 	va_start(args, str);
// 	while (str[i])
// 	{
// 		if (str[i] == '%')
// 		{
// 			len += ft_handle_format(args, str[i + 1]);
// 			i++;
// 		}
// 		else
// 			len += ft_print_char(str[i]);
// 		i++;
// 	}
// 	va_end(args);
// 	return (len);
// }

int	main(void)
{
	int len = ft_printf("test est %c %% %c aeifjae %c\n", 'a', 'b', 'c');
	printf("printf len : %d\n", len);
	return (0);
}
