/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_unsignedlong_base.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 13:50:30 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/04 19:51:42 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_length(unsigned long number, int base)
{
	int	length;

	if (number == 0)
		return (1);
	length = 0;
	while (number != 0)
	{
		number /= base;
		length++;
	}
	return (length);
}

char	*ft_itoa_unsigned_long_base(unsigned long number, int base)
{
	int			needle;
	char		*result;
	const char	*strbase = "0123456789abcdef";

	if (base < 2 || base > 16)
		return (NULL);
	needle = get_number_length(number, base);
	result = malloc(sizeof(char) * needle + 1);
	if (!result)
		return (NULL);
	result[needle] = '\0';
	if (number == 0)
		result[0] = '0';
	while (number > 0)
	{
		needle--;
		result[needle] = strbase[number % base];
		number /= base;
	}
	return (result);
}
