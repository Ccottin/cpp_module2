#include "Fixed.hpp"
#include <iostream>

void	ft_reverse(Fixed a, Fixed b, Fixed c, Fixed d) {
	if (a >= b)
		std::cout << "1 is broken" << std::endl;
	if (b <= a)
		std::cout << "2 is broken" << std::endl;
	if (c != d)
		std::cout << "3 is broken" << std::endl;
	if (a == b)
		std::cout << "4 is broken" << std::endl;
	if (c == b)
		std::cout << "5 is broken" << std::endl;
	if (c > d)
		std::cout << "6 is broken" << std::endl;
	if (c < d)
		std::cout << "7 is broken" << std::endl;
	if (c != c)
		std::cout << "8 is broken" << std::endl;
}

void	ft_test_comparisons(void) {
	Fixed	a (42.42f);
	Fixed	b (42.43f);
	Fixed	c (78);
	Fixed	d = c;

	if (a < b)
		std::cout << "1 passed" << std::endl;
	if (b > a)
		std::cout << "2 passed" << std::endl;
	if (c == d)
		std::cout << "3 passed" << std::endl;
	if (a != b)
		std::cout << "4 passed" << std::endl;
	if (c != b)
		std::cout << "5 passed" << std::endl;
	if (c <= d)
		std::cout << "6 passed" << std::endl;
	if (c >= d)
		std::cout << "7 passed" << std::endl;
	if (c == c)
		std::cout << "8 passed" << std::endl;
	ft_reverse(a, b, c, d);
}

void	ft_test_int(void) {
	Fixed a (3);
	Fixed b (39);
	Fixed c;

	c = a + b;
	std::cout << c << std::endl;
	c = a - b;
	std::cout << c << std::endl;
	c = a * b;
	std::cout << c << std::endl;
	c = a / b;
	std::cout << c << std::endl;
	c = a + a;
	std::cout << c << std::endl;
}

void	ft_test_arithmetics(void) {
	Fixed a (1.5f);
	Fixed b (0.5f);
	Fixed c;

	c = a + b;
	std::cout << c << std::endl;
	c = a - b;
	std::cout << c << std::endl;
	c = a * b;
	std::cout << c << std::endl;
	c = a / b;
	std::cout << c << std::endl;
	c = a + a;
	std::cout << c << std::endl;
	ft_test_int();
}

int	main( void ) {

/*	Fixed	a; Division broken et negatifs ne fonctionnent pas
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
*/
//	ft_test_comparisons();
	ft_test_arithmetics();
	return (0);
}
