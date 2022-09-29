#include "Fixed.hpp"
#include <iostream>

void	test_subject(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;	
}

int	main(void)
{
	test_subject();	
}
