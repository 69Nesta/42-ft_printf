/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:14:46 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/04 11:58:32 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

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
void	test_type_u(void);
void	test_type_x(void);
void	test_type_xx(void);
void	test_tester_1(void);
void	test_tester_2(void);
void	test_tester_3(void);
void	test_tester_4(void);
void	test_tester_5(void);
void	test_fail(void);

int main(void)
{
	// test_type_c();
	// test_type_s();
	// test_type_p();
	// test_type_i();
	// test_type_u();
	// test_type_x();
	// test_type_xx();
	// test_tester_1();
	// test_tester_2();
	// test_tester_3();
	// test_tester_4();
	// test_tester_5();
	test_fail();
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
	TEST("|%p|", 0, 2);
	printf("|%p|\n", 0);
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
	TEST("|%.3i|", 1, 20);
	TEST("|%-.3i|", 1, 21);
	TEST("|%-5.3i|", 1, 21);
	TEST("|%.-3i|", 1, 21);
}

void test_type_u(void)
{
	printf("\n__ TEST TYPE U __\n\n");
	printf("--------------------\n");
	TEST("|%u|", 42, 1);
	TEST("|%u|", (unsigned int)-42, 2);
	TEST("|%5u|", 42, 3);
	TEST("|%5u|", (unsigned int)-42, 4);
	TEST("|%-5u|", 42, 5);
	TEST("|%-5u|", (unsigned int)-42, 6);
	TEST("|%05u|", 42, 7);
	TEST("|%05u|", (unsigned int)-42, 8);
	TEST("|%+u|", 42, 9);
	TEST("|%+u|", (unsigned int)-42, 10);
	TEST("|% u|", 42, 11);
	TEST("|% u|", (unsigned int)-42, 12);
	TEST("|%#u|", 42, 13);
	TEST("|%5.3u|", 42, 14);
	TEST("|%5.3u|", (unsigned int)-42, 15);
	TEST("|%05.3u|", 42, 16);
	TEST("|%-+5u|", 42, 17);
	TEST("|%+05u|", 42, 18);
	TEST("|% 05u|", 42, 19);
	TEST("|%.3u|", 1, 20);
	TEST("|%-.3u|", 1, 21);
	TEST("|%-5.3u|", 1, 22);
	TEST("|%.-3u|", 1, 23);
}

void test_type_x(void)
{
	printf("\n__ TEST TYPE X (hex) __\n\n");
	printf("--------------------\n");

	TEST("|%x|", 42, 1);
	TEST("|%x|", -42, 2);
	TEST("|%5x|", 42, 3);
	TEST("|%5x|", -42, 4);
	TEST("|%-5x|", 42, 5);
	TEST("|%-5x|", -42, 6);
	TEST("|%05x|", 42, 7);
	TEST("|%05x|", -42, 8);
	TEST("|%+x|", 42, 9);
	TEST("|%+x|", -42, 10);
	TEST("|% x|", 42, 11);
	TEST("|% x|", -42, 12);
	TEST("|%#x|", 42, 13);
	TEST("|%5.3x|", 42, 14);
	TEST("|%5.3x|", -42, 15);
	TEST("|%05.3x|", 42, 16);
	TEST("|%-+5x|", 42, 17);
	TEST("|%+05x|", 42, 18);
	TEST("|% 05x|", 42, 19);
	TEST("|%.3x|", 1, 20);
	TEST("|%-.3x|", 1, 21);
	TEST("|%-5.3x|", 1, 22);
	TEST("|%.-3x|", 1, 23);
	TEST("|%#10x|", 42, 24);
	TEST("|%0#10x|", 42, 25);
}

void test_type_xx(void)
{
	printf("\n__ TEST TYPE X (HEX CAPITAL) __\n\n");
	printf("--------------------\n");

	TEST("|%X|", 42, 1);
	TEST("|%X|", -42, 2);
	TEST("|%5X|", 42, 3);
	TEST("|%5X|", -42, 4);
	TEST("|%-5X|", 42, 5);
	TEST("|%-5X|", -42, 6);
	TEST("|%05X|", 42, 7);
	TEST("|%05X|", -42, 8);
	TEST("|%+X|", 42, 9);
	TEST("|%+X|", -42, 10);
	TEST("|% X|", 42, 11);
	TEST("|% X|", -42, 12);
	TEST("|%#X|", 42, 13);
	TEST("|%5.3X|", 42, 14);
	TEST("|%5.3X|", -42, 15);
	TEST("|%05.3X|", 42, 16);
	TEST("|%-+5X|", 42, 17);
	TEST("|%+05X|", 42, 18);
	TEST("|% 05X|", 42, 19);
	TEST("|%.3X|", 1, 20);
	TEST("|%-.3X|", 1, 21);
	TEST("|%-5.3X|", 1, 22);
	TEST("|%.-3X|", 1, 23);
	TEST("|%#10X|", 42, 24);
	TEST("|%0#10X|", 42, 25);
}

void test_tester_1(void)
{
	TEST("%01d|", 0, 1);
	TEST("%012d|", LONG_MIN, 2);
	TEST("%09d|", INT_MAX, 3);
	TEST("%010d|", INT_MIN, 4);
	TEST("%011d|", LONG_MAX, 5)
	TEST("%012d|", LONG_MIN, 6)
	TEST("%013d|", ULONG_MAX, 7)
	TEST("%014d|", 0, 8)
	TEST("%015d|", -42, 9);

	TEST("%01i|", 0, 4);
	TEST("%013i|", UINT_MAX, 5);
	TEST("%01u|", 0, 6);
	TEST("%02u|", -1, 7);
	TEST("%013u|", UINT_MAX, 8);
	TEST("%01x|", 0, 9);
	TEST("%02x|", -1, 10);
	TEST("%013x|", UINT_MAX, 11);
	TEST("%01X|", 0, 12);
	TEST("%02X|", -1, 13);
	TEST("%013X|", UINT_MAX, 13);

	TEST("%.s|", "-", 14);
	// TEST(" %01d ", 0, 13);
	// TEST(" %01d ", 0, 13);
	// TEST(" %01d ", 0, 13);
	// TEST(" %01d ", 0, 13);
}

void test_tester_2(void)
{
	TEST("%.2d|", -1, 11);
	TEST("%.2d|", 1, 12);
	TEST("%.3d|", 11, 15);
	TEST("%.4d|", 15, 16);
	TEST("%.5d|", 16, 17);
	TEST("%.6d|", 17, 18);
	TEST("%.3d|", -11, 24);
	TEST("%.4d|", -14, 25);
	TEST("%.3d|", -99, 28);
	TEST("%.4d|", -101, 30);
	TEST("%.10d|", LONG_MAX, 33);
	TEST("%.11d|", LONG_MIN, 34);
	TEST("%.12d|", UINT_MAX, 35);
	TEST("%.13d|", ULONG_MAX, 36);
	TEST("%.14d|", 9223372036854775807LL, 38);
	TEST("%.8d|", INT_MAX, 39);
	TEST("%.9d|", INT_MIN, 39);
	TEST("%.10d|", LONG_MAX, 39);
	TEST("%.11d|", LONG_MIN, 39);
	TEST("%.12d|", ULONG_MAX, 39);
	TEST("%.13d|", 0, 39);
	TEST("%.14d|", -42, 39);
	TEST("%.2i|", -1, 40);
	TEST("%.2i|", 1, 41);
	TEST("%.3i|", 11, 44);
	TEST("%.4i|", 15, 45);
	TEST("%.5i|", 16, 46);
	TEST("%.6i|", 17, 47);
	TEST("%.3i|", -11, 53);
	TEST("%.4i|", -14, 54);
	TEST("%.3i|", -99, 57);
	TEST("%.4i|", -101, 59);
	TEST("%.10i|", LONG_MAX, 62);
	TEST("%.11i|", LONG_MIN, 63);
	TEST("%.12i|", UINT_MAX, 64);
	TEST("%.13i|", ULONG_MAX, 65);
	TEST("%.14i|", 9223372036854775807LL, 66);
	TEST("%.8i|", INT_MAX, 67);
	TEST("%.9i|", INT_MIN, 67);
	TEST("%.10i|", LONG_MAX, 67);
	TEST("%.11i|", LONG_MIN, 67);
	TEST("%.12i|", ULONG_MAX, 67);
	TEST("%.13i|", 0, 67);
	TEST("%.14i|", -42, 67);
}

void	test_tester_3(void)
{
	TEST("%#x|", 0, 1);
	TEST("%#x|", LONG_MIN, 25);
	TEST("%#x|", INT_MAX, 29);
	// TEST("%#x|", INT_MIN, 29);
	// TEST("%#x|", LONG_MAX, 29);
	// TEST("%#x|", LONG_MIN, 29);
	// TEST("%#x|", ULONG_MAX, 29);
	// TEST("%#x|", 0, 29);
	// TEST("%#x|", -42, 29);
	// TEST("%#X|", 0, 31);
	// TEST("%#X|", LONG_MIN, 55);
	// TEST("%#X|", INT_MAX, 59);
	// TEST("%#X|", INT_MIN, 59);
	// TEST("%#X|", LONG_MAX, 59);
	// TEST("%#X|", LONG_MIN, 59);
	// TEST("%#X|", ULONG_MAX, 59);
	// TEST("%#X|", 0, 59);
	// TEST("%#X|", -42, 59);
}

void	test_tester_4(void)
{
	TEST("%010.5i|", -216, 1);
	TEST("%08.3i|", -8473, 2);
	TEST("%.0i|", 0, 3);
	TEST("%.0i|", 2, 4);
	TEST("%5.0i|", 0, 5);
	TEST("%.0u|", 0, 6);
	TEST("%3.0u|", 0, 7);
	TEST("%.0x|", 0, 8);
	TEST("%3.0x|", 0, 9);
	TEST("%.X|", 0, 10);
	TEST("%4.X|", 0, 11);
	// TEST("%5.0i|", 0, 5);
	// TEST("%5.0i|", 0, 5);
	// TEST("%5.0i|", 0, 5);
	// TEST("%5.0i|", 0, 5);
	
}

void	test_tester_5(void)
{
	// printf("--------%3d --------\n", 1); \
	// ft_printf("%197c\n%12p\n%013.i\n%--147.185x\n%-1c" ,7,(void*)18229185041105221837lu,-1488496170,703835510u,120);             \
	// printf("\n");                         \
	// printf("%197c\n%12p\n%013.i\n%--147.185x\n%-1c" ,7,(void*)18229185041105221837lu,-1488496170,703835510u,120);                \
	// printf("\n--------------------\n");
	// TEST("%197c%12p%013.i%--147.185x%-1c" ,7,(void*)18229185041105221837lu,-1488496170,703835510u,120, 1);
	TEST("%013.i|", -1488496170, 1);
}

void	test_fail(void)
{
	// fail on c
	ft_printf("%d %c %i\n", 1, '2', 3);
}
