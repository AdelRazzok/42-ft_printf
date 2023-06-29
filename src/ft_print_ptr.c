#include "../include/ft_printf.h"

static void	ft_putnbr_hex(uintptr_t nbr)
{
	char	*hex_digits = "0123456789abcdef";

	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16);
	write(1, &hex_digits[nbr % 16], 1);
}

int	ft_print_ptr(void *ptr)
{
	uintptr_t	address;
	int			len;

	address = (uintptr_t)ptr;
	len = 2;
	write(1, "0x", 2);
	ft_putnbr_hex(address);
	while (address >= 16)
	{
		address /= 16;
		len++;
	}
	return (len);
}
