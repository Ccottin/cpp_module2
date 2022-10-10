/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:39:31 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/10 22:39:46 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << c << " should be 42" << std::endl;
	c = a - b;
	std::cout << c << " should be -36" << std::endl;
	c = a * b;
	std::cout << c << " should be 117" <<  std::endl;
	c = a / b;
	std::cout << c << " should be " << a/b <<  std::endl;
	c = a + a;
	std::cout << c << " should be 6" << std::endl;
	a = a - a;
	std::cout << a << " should be 0" << std::endl;
}

void	ft_test_arithmetics(void) {
	Fixed a (1.5f);
	Fixed b (0.5f);
	Fixed c;

	c = a + b;
	std::cout << c << " should be 2" << std::endl;
	c = a - b;
	std::cout << c << " should be 1" << std::endl;
	c = a * b;
	std::cout << c << " should be 0.75" << std::endl;
	c = a / b;
	std::cout << c << " should be 3" << std::endl;
	c = a + a;
	std::cout << c << " should be 3" << std::endl;
	a = a - a;
	std::cout << a << " should be 0" << std::endl;
	ft_test_int();
}

void	ft_test_iterators(void)
{
	 Fixed a;

	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
}

void	ft_test_minmax(void)
{
	{
		Fixed a(8.5f);
		Fixed b(8.3f);
	
		std::cout << Fixed::min(a, b) << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	{
		Fixed const a(8.5f);
		Fixed const b(8.3f);
	
		std::cout << Fixed::min(a, b) << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	{
		Fixed a(-8);
		Fixed b(-3);
	
		std::cout << Fixed::min(a, b) << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	{
		Fixed const a(-8);
		Fixed const b(-3);
	
		std::cout << Fixed::min(a, b) << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
}

int	main( void ) {

	Fixed	a;
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
//	ft_test_comparisons();
//	ft_test_arithmetics();
//	ft_test_iterators();
//	ft_test_minmax();
	return (0);
}
