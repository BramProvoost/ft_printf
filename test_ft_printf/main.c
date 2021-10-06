/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 10:42:48 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/04 19:56:52 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <limits.h>

int	main(void)
{
	int	dif;

	printf("Start test\n");
	test_char('a');
	test_char('%');
	test_string("Test\0 string");
	test_string("Test string");
	test_number(0);
	test_string(NULL);
	test_number(42);
	test_number(INT32_MAX);
	test_number(-42);
	test_number(INT32_MIN);
	dif = ft_printf("'test%c%%X%X%%%% %c'\n", '@', 42, '!');
	dif -= printf("'test%c%%X%X%%%% %c'\n", '@', 42, '!');
	print_dif(dif);
	dif = ft_printf("p max: '%p'\n", ULLONG_MAX);
	dif -= printf("p max: '0x%llx'\n", ULLONG_MAX);
	print_dif(dif);
	ft_printf("String with specifier: %s\n", "(remove this)");
	printf("End test\n");
	printf(GRAY LINE YELLOW "Test leaks" GRAY LINE"\n");
	system("leaks test");
	printf(GRAY LINE YELLOW "End leaks" GRAY LINE NO_COLOR"\n");
	return (0);
}

void	print_dif(int dif)
{
	printf(GRAY LINE NO_COLOR);
	if (dif == 0)
		printf(GREEN" OK "NO_COLOR);
	else
		printf(RED"DIF: %d"NO_COLOR, dif);
	printf(GRAY LINE NO_COLOR);
	printf("\n");
}

void	test_char(char c)
{
	int	dif;

	dif = 0;
	if (c == '%')
	{
		dif += ft_printf("%%: '%%'\n");
		dif -= printf("%%: '%%'\n");
	}
	else
	{
		dif += ft_printf("c: '%c'\n", c);
		dif -= printf("c: '%c'\n", c);
	}
	print_dif(dif);
}

void	test_string(char *str)
{
	int	dif;

	dif = 0;
	dif += ft_printf("s: '%s'\n", str);
	dif -= printf("s: '%s'\n", str);
	print_dif(dif);
	dif += ft_printf("p: '%p'\n", &str);
	dif -= printf("p: '%p'\n", &str);
	print_dif(dif);
}

void	test_number(int nr)
{
	int	dif;

	dif = 0;
	dif += ft_printf("d: '%d'\n", nr);
	dif -= printf("d: '%d'\n", nr);
	print_dif(dif);
	dif += ft_printf("i: '%i'\n", nr);
	dif -= printf("i: '%i'\n", nr);
	print_dif(dif);
	dif += ft_printf("u: '%u'\n", nr);
	dif -= printf("u: '%u'\n", nr);
	print_dif(dif);
	dif += ft_printf("x: '%x'\n", nr);
	dif -= printf("x: '%x'\n", nr);
	print_dif(dif);
	dif += ft_printf("X: '%X'\n", nr);
	dif -= printf("X: '%X'\n", nr);
	print_dif(dif);
}
