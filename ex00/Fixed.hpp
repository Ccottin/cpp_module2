#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed {

	public :

	Fixed(void);
	Fixed(const Fixed &f);
	
	~Fixed(void);

	private :

	int			_number;
	const static int	_bits;
};

#endif
