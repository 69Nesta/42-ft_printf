/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:14:46 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/28 16:36:32 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

#define TEST(FORMAT, VALUE, ID)           \
	printf("--------%3d --------\n", ID); \
	ft_printf(FORMAT, VALUE);             \
	printf("\n");                         \
	printf(FORMAT, VALUE);                \
	printf("\n--------------------\n");

void	test_type_c(void);
void	test_type_s(void);
void	test_type_p(void);
void	test_type_i(void);

int main(void)
{
	// test_type_c();
	// test_type_s();
	// test_type_p();
	test_type_i();
}

void test_type_c(void)
{
	printf("\n__ TEST TYPE C __\n\n");
	printf("----------------\n");
	TEST("|%c|", 'H', 1);
	TEST("|%5c|", 'H', 2);
	TEST("|%-5c|", 'H', 3);
	TEST("|%5.3c|", 'H', 4);
	TEST("|%.3c|", 'H', 5);
	TEST("|%+5c|", 'H', 6);
	TEST("|% 5c|", 'H', 7);
	TEST("|%#5c|", 'H', 8);
	TEST("|%05c|", 'H', 9);
	TEST("|%-05c|", 'H', 10);
	TEST("|%+05c|", 'H', 11);
}

void test_type_s(void)
{
	const char string[] = "Hell";
	printf("\n__ TEST TYPE S __\n\n");
	printf("--------------------\n");
	TEST("|%s|", string, 1);
	TEST("|%s|", NULL, 2);
	TEST("|%5s|", string, 3);
	TEST("|%5s|", NULL, 4);
	TEST("|%-5s|", string, 5);
	TEST("|%-5s|", NULL, 6);
	TEST("|%5.3s|", string, 7);
	TEST("|%5.3s|", NULL, 8);
	TEST("|%.3s|", string, 9);
	TEST("|%.3s|", NULL, 10);
	TEST("|%+5s|", string, 11);
	TEST("|%+5s|", NULL, 12);
	TEST("|% 5s|", string, 13);
	TEST("|% 5s|", NULL, 14);
	TEST("|%#5s|", string, 15);
	TEST("|%#5s|", NULL, 16);
	TEST("|%05s|", string, 17);
	TEST("|%05s|", NULL, 18);
	TEST("|%-05s|", string, 19);
	TEST("|%-05s|", NULL, 20);
	TEST("|%+05s|", string, 21);
	TEST("|%+05s|", NULL, 22);
}

void test_type_p(void)
{
	int a = 42;
	void *ptr = (void *)&a;
	void *null_ptr = NULL;

	printf("\n__ TEST TYPE P __\n\n");
	printf("--------------------\n");
	TEST("|%p|", ptr, 1);
	TEST("|%p|", null_ptr, 2);
	TEST("|%15p|", ptr, 3);
	TEST("|%15p|", null_ptr, 4);
	TEST("|%-15p|", ptr, 5);
	TEST("|%-15p|", null_ptr, 6);
	TEST("|%015p|", ptr, 7);
	TEST("|%015p|", null_ptr, 8);
	TEST("|%+p|", ptr, 9);
	TEST("|%+p|", null_ptr, 10);
	TEST("|% p|", ptr, 11);
	TEST("|% p|", null_ptr, 12);
	TEST("|%#p|", ptr, 13);
	TEST("|%#p|", null_ptr, 14);
	TEST("|%-015p|", ptr, 15);
	TEST("|%-015p|", null_ptr, 16);
	TEST("|%+ p|", ptr, 17);
	TEST("|%+ p|", null_ptr, 18);
}

void test_type_i(void)
{
	printf("\n__ TEST TYPE I/D __\n\n");
	printf("--------------------\n");
	TEST("|%i|", 42, 1);
	TEST("|%i|", -42, 2);
	TEST("|%5i|", 42, 3);
	TEST("|%5i|", -42, 4);
	TEST("|%-5i|", 42, 5);
	TEST("|%-5i|", -42, 6);
	TEST("|%05i|", 42, 7);
	TEST("|%05i|", -42, 8);
	TEST("|%+i|", 42, 9);
	TEST("|%+i|", -42, 10);
	TEST("|% i|", 42, 11);
	TEST("|% i|", -42, 12);
	TEST("|%#i|", 42, 13);
	TEST("|%5.3i|", 42, 14);
	TEST("|%5.3i|", -42, 15);
	TEST("|%05.3i|", 42, 16);
	TEST("|%-+5i|", 42, 17);
	TEST("|%+05i|", 42, 18);
	TEST("|% 05i|", 42, 19);
	TEST("|%.3i|", 0, 20);
}
