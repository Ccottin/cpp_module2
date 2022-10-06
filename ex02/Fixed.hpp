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

	Fixed operator+(Fixed const &f) const;
	Fixed operator-(Fixed const &f) const;
	Fixed operator*(Fixed const &f) const;
	Fixed operator/(Fixed const &f) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	float	toFloat(void) const;
	int	toInt(void) const;
	int	getRawBits(void) const;
	void	setRawBits(int const raw);

	static Fixed	&min(Fixed &f, Fixed &g);
	static Fixed	&min(Fixed const &f, Fixed const &g);
	static Fixed	&max(Fixed &f, Fixed &g);
	static Fixed	&max(Fixed const &f, Fixed const &g);

	private :

	int			_number;
	const static int	_bits = 8;
};

std::ostream &	operator<<(std::ostream & stream, Fixed const & f);

#endif

/* Les surchages d operateurs d operation arithmetiques renvoient un Objet */
/* non pas une reference, car elle pointerait sur une variable locale, et  */
/* nous on cherche a obtenir le resultat d une opearation entre deux objets*/
/* il serait donc pas possible de recuperer le resultat, dnc on appelle un */
/* constructeur 							   */

/* Les fonctions statics n'ont pas de pointeur this, et le mot cle const   */
/* affecte le pointeur this de la classe, une fonction membre ne peut pas  */
/* etre const et static							   */
