/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:53:33 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/10 21:53:40 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {

	public :

	Fixed(void);
	Fixed(int const n);
	Fixed(float const f);
	Fixed(Fixed const &f);
	Fixed &operator=(Fixed const &f);	
	~Fixed(void);
	float	toFloat(void) const;
	int	toInt(void) const;
	int	getRawBits(void) const;
	void	setRawBits(int const raw);

	private :

	int			_number;
	const static int	_bits = 8;
};

std::ostream &	operator<<(std::ostream & stream, Fixed const & f);

#endif
