#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _number(0) { 
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" <<std::endl;
	this->_number = n * (2^this->_bits);	
}

Fixed::Fixed(float const n) {
std::cout << "Float constructor called" <<std::endl;

	float	temp;
	
	temp = n * (float)(2^(this->_bits));
	this->_number = roundf(temp);
}

Fixed::Fixed(const Fixed & f) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &f)
		this->_number = f.getRawBits();
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed & f) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->_number = f.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream & stream, Fixed const & f) {
	stream << f.toFloat();
	return (stream);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}

int	Fixed::toInt(void) const {
	return (this->_number / (2^this->_bits));
}
float	Fixed::toFloat(void) const {
	
	float	temp;

	temp = this->_number / (float)(2^this->_bits);
	return (temp);
}
