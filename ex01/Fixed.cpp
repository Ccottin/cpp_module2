/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:53:30 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/10 21:53:40 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <string>
#include <iostream>
#include <cmath>

float	power(int value, int power)
{
	int	res;

	res = 1;
	while (0 < power)
	{
		res *= value;
		power--;
	}
	return (res);
}

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
	return (this->_number / power(2, this->_bits));
}
float	Fixed::toFloat(void) const {
	
	return (this->_number / power(2, this->_bits));
}
