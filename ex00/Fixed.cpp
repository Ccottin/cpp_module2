#include "Fixed.hpp"
#include <string>
#include <iostream>

Fixed::Fixed(void) : _number(0) { 
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &f)
		this->_number = f.getRawBits();
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->_number = f.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}
