#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed {

	public :

	Fixed(void);
	Fixed(const Fixed &f);
	Fixed &operator=(const Fixed &f);	
	~Fixed(void);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);

	private :

	int			_number;
	const static int	_bits = 8;
};

#endif
