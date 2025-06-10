/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:58:59 by amhan             #+#    #+#             */
/*   Updated: 2025/06/01 16:28:24 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	test_ft_print_s(void)
{
	char	*s;
	char	*str;

	printf("----------*str = \"Hello World\"----------\n");
	s = "Hello World";
	ft_printf("My printf : %s\n", s);
	printf("Original  : %s\n", s);
	printf("----------*str = NULL----------\n");
	str = NULL;
	ft_printf("My printf : %s\n", str);
	printf("Original  : %s\n", str);
}

static void	test_ft_print_c(void)
{
	char	c;
	char	mod;

	printf("---------- one character ----------\n");
	c = 'A';
	ft_printf("My printf : %c\n", c);
	printf("Original  : %c\n", c);
	printf("---------- modulo ----------\n");
	mod = '%';
	ft_printf("My printf : %c\n", mod);
	printf("Original  : %c\n", mod);
}

static void	test_ft_print_d(void)
{
	int	nb;
	int	nbr;

	printf("---------- decimals (d) ----------\n");
	nb = INT_MIN;
	ft_printf("My printf : %d\n", nb);
	printf("Original  : %d\n", nb);
	printf("---------- decimals (i) ----------\n");
	nbr = -1234;
	ft_printf("My printf : %i\n", nbr);
	printf("Original  : %i\n", nbr);
}

static void	test_ft_print_u(void)
{
	int	nb;

	printf("---------- unsigned decimal ----------\n");
	nb = INT_MAX;
	ft_printf("My printf : %u\n", nb);
	printf("Original  : %u\n", nb);
}

static void	test_ft_print_p(void)
{
	void	*null_ptr;
	int		var;
	char	*string;

	printf("---------- pointer (p) ----------\n");
	null_ptr = NULL;
	ft_printf("My printf : %p\n", null_ptr);
	printf("Original  : %p\n", null_ptr);
	printf("---------- address var ----------\n");
	var = 42;
	ft_printf("My printf : %p\n", &var);
	printf("Original  : %p\n", &var);
	printf("---------- address string ----------\n");
	string = "Hello";
	ft_printf("My printf : %p\n", &string);
	printf("Original  : %p\n", &string);
}

static void	test_ft_print_x(void)
{
	int	nb;

	printf("---------- hex to lowercase ----------\n");
	nb = 42;
	ft_printf("My printf : %x\n", nb);
	printf("Original  : %x\n", nb);
}

static void	test_ft_print_X(void)
{
	int	nb;

	printf("---------- hex to uppercase ----------\n");
	nb = 42;
	ft_printf("My printf : %X\n", nb);
	printf("Original  : %X\n", nb);
}

static void	test_bugs(void)
{
	printf("---------- if(format == NULL) ----------\n");
	printf("My printf : %d\n", ft_printf(NULL));
	printf("Original : %d\n", printf(0));
}
static void test_return_val(void)
{
	printf("---------- return value ----------\n");
	ft_printf("%d\n", ft_printf("My printf : %x\n", 25487));
	printf("%d\n", printf("Original  : %x\n", 25487));
}

int	main(void)
{
	test_ft_print_s();
	test_ft_print_c();
	test_ft_print_d();
	test_ft_print_u();
	test_ft_print_p();
	test_ft_print_x();
	test_ft_print_X();
	test_bugs();
	test_return_val();
	return (0);
}

