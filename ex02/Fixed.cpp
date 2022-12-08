#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->setRawBits(0);
}

Fixed::Fixed(const int val)
{
	this->value = val << this->bits;
}

Fixed::Fixed(const float val)
{
	this->value = roundf(val * (1 << this->bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed(void){}

int Fixed::toInt(void) const 
{
	return ((int) this->value >> this->bits);
}

float Fixed::toFloat(void) const 
{
	return ((float) this->value / (1 << this->bits));
}

void Fixed::operator=(const Fixed &copy)
{
	this->setRawBits(copy.getRawBits());
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(const int raw)
{
	this->value = raw;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &x)
{
	stream << x.toFloat();
	return(stream);
}

Fixed	Fixed::operator+(const Fixed &n) const
{ return (Fixed(this->toFloat() + n.toFloat())); }

Fixed	Fixed::operator-(const Fixed &n) const
{ return (Fixed(this->toFloat() - n.toFloat())); }

Fixed	Fixed::operator*(const Fixed &n) const
{ return (Fixed((float) this->toFloat() * (float) n.toFloat())); }

Fixed	Fixed::operator/(const Fixed &n) const
{ return (Fixed((float) this->toFloat() / (float) n.toFloat())); }

bool	Fixed::operator>(const Fixed &n) const
{ return (this->value > n.getRawBits()); }

bool	Fixed::operator<(const Fixed &n) const
{ return (this->value < n.getRawBits()); }

bool	Fixed::operator>=(const Fixed &n) const
{ return (this->value >= n.getRawBits()); }

bool	Fixed::operator<=(const Fixed &n) const
{ return (this->value <= n.getRawBits()); }

bool	Fixed::operator==(const Fixed &n) const
{ return (this->value == n.getRawBits()); }

bool	Fixed::operator!=(const Fixed &n) const
{ return !(*this == n); }

Fixed&	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	newFixed(*this);
	++(*this);
	return (newFixed);
}

Fixed&	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	newFixed(*this);
	--(*this);
	return (newFixed);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}