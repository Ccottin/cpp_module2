#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

extern bool	b0;
extern bool	b1;

class	Fixed {

	public :

	Fixed(void);
	Fixed(int const n);
	Fixed(float const f);
	Fixed(Fixed const &f); 
	~Fixed(void);

	Fixed &operator=(Fixed const &f);	
	
	bool  &operator>(Fixed const &f);
	bool  &operator<(Fixed const &f);
	bool  &operator>=(Fixed const &f);
	bool  &operator<=(Fixed const &f);
	bool  &operator==(Fixed const &f);
	bool  &operator!=(Fixed const &f);

	Fixed &operator+(Fixed const &f);
	Fixed &operator-(Fixed const &f);
	Fixed &operator*(Fixed const &f);
	Fixed &operator/(Fixed const &f);

	Fixed &operator++(void);
	Fixed &operator++(int);
	Fixed &operator--(void);
	Fixed &operator--(int);

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
