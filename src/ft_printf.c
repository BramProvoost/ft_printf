/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 10:16:15 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/20 15:54:07 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	go_through_format(const char *format, va_list args);

static int	put_argument(va_list args, char conversion);

static int	put_chars(va_list args, char conversion);

static int	put_numbers(va_list args, char conversion);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	va_start(args, format);
	length = go_through_format(format, args);
	va_end(args);
	return (length);
}

static int	go_through_format(const char *format, va_list args)
{
	int	index;
	int	length;

	index = 0;
	length = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			length += put_argument(args, format[index]);
		}
		else
			length += ft_putchar_fd(format[index], 1);
		index++;
	}
	return (length);
}

static int	put_argument(va_list args, char conversion)
{
	if (ft_strchr("%cs", conversion))
		return (put_chars(args, conversion));
	else if (ft_strchr("pduixX", conversion))
		return (put_numbers(args, conversion));
	return (ft_putchar_fd(conversion, 1));
}

static int	put_chars(va_list args, char conversion)
{
	int		length;
	char	*str;

	length = 0;
	if (conversion == 'c')
		length = ft_putchar_fd(va_arg(args, int), 1);
	else if (conversion == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			length = ft_putstr_fd("(null)", 1);
		else
			length = ft_putstr_fd(str, 1);
	}
	else if (conversion == '%')
		length = ft_putchar_fd('%', 1);
	return (length);
}

static int	put_numbers(va_list args, char conversion)
{
	int		length;
	char	*str;

	length = 0;
	str = NULL;
	if (conversion == 'p')
	{
		length = ft_putstr_fd("0x", 1);
		str = ft_itoa_unsigned_long_base((long long)va_arg(args, void *), 16);
	}
	else if (conversion == 'd' || conversion == 'i')
		str = ft_itoa_long_base(va_arg(args, int), 10);
	else if (conversion == 'u')
		str = ft_itoa_long_base(va_arg(args, unsigned int), 10);
	else if (conversion == 'x' || conversion == 'X')
		str = ft_itoa_long_base(va_arg(args, unsigned int), 16);
	if (conversion == 'X')
		ft_strtoupper(str);
	if (!str)
		return (0);
	length += ft_putstr_fd(str, 1);
	free(str);
	str = NULL;
	return (length);
}
