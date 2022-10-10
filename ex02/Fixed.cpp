/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:39:36 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/10 22:39:52 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/* Commentaires sur tous les appels pour plus de lisibilite */

Fixed::Fixed(void) : _number(0) { 
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) {
//	std::cout << "Int constructor called" <<std::endl;
	this->_number = n * power(2, this->_bits);	
}

Fixed::Fixed(float const n) {
//	std::cout << "Float constructor called" <<std::endl;

	float	temp;
	
	temp = n * power(2, this->_bits);	
	this->_number = roundf(temp);
}

Fixed::Fixed(const Fixed & f) {
//	std::cout << "Copy constructor called" << std::endl;
	if (this != &f)
		this->_number = f.getRawBits();
}

Fixed::~Fixed(void) {
//	std::cout << "Destructor called" << std::endl;
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

Fixed	Fixed::operator+(Fixed const &f) const {
	float	temp;
	Fixed	Temp;

	temp = (this->toFloat() + f.toFloat()) * power(2, 8);
	Temp.setRawBits(roundf(temp));
	return (Temp);
}

Fixed	Fixed::operator-(Fixed const &f) const {
	float	temp;
	Fixed	Temp;

	temp = (this->toFloat() - f.toFloat()) * power(2, 8);
	Temp.setRawBits(roundf(temp));
	return (Temp);
}

Fixed	Fixed::operator*(Fixed const &f) const {
	float	temp;
	Fixed	Temp;

	temp = (this->toFloat() * f.toFloat()) * power(2, 8);
	Temp.setRawBits(roundf(temp));
	return (Temp);
}

Fixed	Fixed::operator/(Fixed const &f) const {
	float	temp;
	Fixed	Temp;

	temp = (this->toFloat() / f.toFloat()) * power(2, 8);
	Temp.setRawBits(roundf(temp));
	return (Temp);
}

Fixed	Fixed::operator++(int) {
	Fixed	Temp;

	Temp = *this;
	++(*this);
	return (Temp);
}

Fixed	&Fixed::operator++(void) {
	(this->_number)++;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	Temp;

	Temp = *this;
	--(*this);
	return (Temp);
}

Fixed	&Fixed::operator--(void) {
	(this->_number)--;
	return (*this);
}

Fixed	&Fixed::operator=(const Fixed & f) {
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->_number = f.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream & stream, Fixed const & f) {
	stream << f.toFloat();
	return (stream);
}

/* Member Fonctions */

int	Fixed::getRawBits(void) const {
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void	Fixed::setRawBits(int const raw) {
//	std::cout << "setRawBits member function called" << std::endl;
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

Fixed	&Fixed::min(Fixed &f, Fixed &g) {
	if (f.getRawBits() < g.getRawBits())
		return (f);
	else
		return (g);
}
Fixed	Fixed::min(Fixed const &f, Fixed const &g) {
	if (f.getRawBits() < g.getRawBits())
	{
		Fixed	Temp(f);
		return (Temp);
	}
	else
	{
		Fixed	Temp(g);
		return (Temp);
	}
}

Fixed	&Fixed::max(Fixed &f, Fixed &g) {
	if (f.getRawBits() > g.getRawBits())
		return (f);
	else
		return (g);
}

Fixed	Fixed::max(Fixed const &f, Fixed const &g) {
	if (f.getRawBits() > g.getRawBits())
	{
		Fixed	Temp(f);
		return (Temp);
	}
	else
	{
		Fixed	Temp(g);
		return (Temp);
	}
}
