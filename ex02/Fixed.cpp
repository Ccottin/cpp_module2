#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <cmath>

/* Misc */

bool	b0 = false;
bool	b1 = true;

float	power(int value, int power)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (i < power)
	{
		res *= value;
		i++;
	}
	return (res);
}

/* Constructors & Destructor */

Fixed::Fixed(void) : _number(0) { 
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" <<std::endl;
	this->_number = n * power(2, this->_bits);	
}

Fixed::Fixed(float const n) {
std::cout << "Float constructor called" <<std::endl;

	float	temp;
	
	temp = n * power(2, this->_bits);	
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

/* Operators Overload */

bool	&Fixed::operator>(const Fixed & f) {
	if (this == &f)
		return (b0);
	if (this->_number > f.getRawBits())
		return (b1);
	return (b0);
}

bool	&Fixed::operator<(const Fixed & f) {
	if (this == &f)
		return (b0);
	if (this->_number < f.getRawBits())
		return (b1);
	return (b0);
}

bool	&Fixed::operator>=(const Fixed & f) {
	if (this == &f)
		return (b1);
	if (this->_number >= f.getRawBits())
		return (b1);
	return (b0);
}

bool	&Fixed::operator<=(const Fixed & f) {
	if (this == &f)
		return (b1);
	if (this->_number <= f.getRawBits())
		return (b1);
	return (b0);
}

bool	&Fixed::operator==(const Fixed & f) {
	if (this == &f)
		return (b1);
	if (this->_number == f.getRawBits())
		return (b1);
	return (b0);
}

bool	&Fixed::operator!=(const Fixed & f) {
	if (this == &f)
		return (b0);
	if (this->_number != f.getRawBits())
		return (b1);
	return (b0);
}

Fixed	&Fixed::operator+(Fixed const &f) {
	float	temp;

	temp = (this->toFloat() + f.toFloat()) * power(2, 8);
	this->_number = roundf(temp);
	return (*this);
}

Fixed	&Fixed::operator-(Fixed const &f) { //sign?
	float	temp;

	temp = (this->toFloat() - f.toFloat());
	std::cout << "temp = " << temp << "this " << this->toFloat() << " f " << f.toFloat() << std::endl;
	temp *= power(2, 8);
	this->_number = (int)roundf(temp);
	return (*this);
}

Fixed	&Fixed::operator*(Fixed const &f) {
	float	temp;

	temp = (this->toFloat() * f.toFloat()) * power(2, 8);
	this->_number = roundf(temp);
	return (*this);
}

Fixed	&Fixed::operator/(Fixed const &f) {
	float	temp;

	temp = (this->toFloat() / f.toFloat()) * power(2, 8);
	this->_number = roundf(temp);
	return (*this);
}

/*
Fixed	&Fixed::operator(const Fixed & f) {
	if (this == &f)
		return ;

}

Fixed	&Fixed::operator(const Fixed & f) {
	if (this == &f)
		return ;

}*/
Fixed	&Fixed::operator=(const Fixed & f) {
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

/* Member Fonctions */

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}

int	Fixed::toInt(void) const {
	return (this->_number / power(2, this->_bits));
}
float	Fixed::toFloat(void) const {
	
	float	temp;

	temp = this->_number / power(2, this->_bits);
	return (temp);
}
