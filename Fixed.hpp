//
// Created by Bogdan Semchuk on 1/18/18.
//

#ifndef D02_FIXED_HPP
#define D02_FIXED_HPP

#include <iostream>

class Fixed {
public:

	Fixed();
	Fixed(int const i);
	Fixed(float const f);
	Fixed(Fixed const &fixed);
	~Fixed();

	Fixed &operator=(Fixed const &fixed);

	bool	operator>(Fixed const &fixed) const;
	bool	operator<(Fixed const &fixed) const;
	bool	operator<=(Fixed const &fixed) const ;
	bool	operator>=(Fixed const &fixed) const ;
	bool	operator==(Fixed const &fixed) const ;
	bool	operator!=(Fixed const &fixed) const ;

	Fixed	operator+(Fixed const &fixed) const;
	Fixed	operator-(Fixed const &fixed) const;
	Fixed	operator*(Fixed const &fixed) const;
	Fixed	operator/(Fixed const &fixed) const;

	Fixed	operator ++();
	Fixed	operator ++(int);
	Fixed	operator --();
	Fixed	operator --(int);

	static Fixed &max(Fixed &fixed, Fixed &fixed2);
	static const Fixed	&max(Fixed const &fixed, Fixed const &fixed2);
	static Fixed &min(Fixed &fixed, Fixed &fixed2);
	static const Fixed	&min(Fixed const &fixed, Fixed const &fixed2);

	float toFloat(void) const;
	int toInt(void) const;

	void	setRawBits(int const raw);
	int 	getRawBits(void) const;

private:

	int	_fixedPoint;
	static const int _rawBits = 8;
};

std::ostream &operator<<(std::ostream &output, Fixed const &fixed);

#endif //D02_FIXED_HPP
