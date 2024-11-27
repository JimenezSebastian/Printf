/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 02:54:04 by almejia-          #+#    #+#             */
/*   Updated: 2024/09/18 12:46:31 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_all(unsigned long long num, int d, int alert, const char *hex_chars)
{
	static int	c = 0;

	if (alert == 2 && !num)
		return (write(1, "(nil)", 5));
	if (alert == 4 && !hex_chars)
		return (write(1, "(null)", 6));
	if (alert == 0 || alert == 2 || alert == 4)
		c = 0;
	if (alert == 4)
	{
		while (hex_chars[c])
			c += write(1, &hex_chars[c], 1);
		return (c);
	}
	if (alert == 2)
		c += write(1, "0x", 2);
	alert = 3;
	if (num >= (unsigned long long)d)
		ft_all(num / d, d, alert, hex_chars);
	c += write(1, &hex_chars[(num % d)], 1);
	return (c);
}

int	ft_ext_pf(const char *format, va_list args)
{
	int		c;
	int		num;
	char	one_char;

	c = 0;
	num = 0;
	if (*format == 'd' || *format == 'i')
	{
		num = va_arg(args, int);
		if (num < 0)
		{
			if (num == -2147483648)
				return (write(1, "-2147483648", 11));
			c += write(1, "-", 1);
			num = -num;
		}
		c += ft_all((unsigned long long)num, 10, 0, "0123456789abcdef");
		return (c);
	}
	one_char = (char)va_arg(args, int);
	c += write(1, &one_char, 1);
	return (c);
}

int	ft_process_format(const char *format, va_list args)
{
	if (*format == '%')
		return (write(1, "%", 1));
	if (*format == 's')
		return (ft_all(1, 10, 4, (const char *)va_arg(args, char *)));
	if (*format == 'u')
		return (ft_all((unsigned long long)va_arg(args, unsigned int),
				10, 0, "0123456789abcdef"));
	if (*format == 'x')
		return (ft_all((unsigned long long)va_arg(args, unsigned int),
				16, 0, "0123456789abcdef"));
	if (*format == 'X')
		return (ft_all((unsigned long long)va_arg(args, unsigned int),
				16, 0, "0123456789ABCDEF"));
	if (*format == 'p')
		return (ft_all((unsigned long long)va_arg(args, void *),
				16, 2, "0123456789abcdef"));
	if (*format == 'd' || *format == 'i' || *format == 'c')
		return (ft_ext_pf(format, args));
	return (-1);
}

int	ft_search_format(const char *format, va_list args)
{
	int	c;
	int	aux;

	c = 0;
	aux = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			aux = ft_process_format(format, args);
			if (aux == -1)
				c += write(1, "%", 1);
			else
				c += aux;
		}
		else
			c += write (1, format, 1);
		format++;
	}
	return (c);
}

int	ft_printf(const char *format, ...)
{
	int		c;
	va_list	args;

	c = 0;
	va_start(args, format);
	if (!format)
		return (0);
	c += ft_search_format(format, args);
	va_end(args);
	return (c);
}
