#include <iostream>
#include <cmath>

class Fixed 
{
	private:
		static const int bits = 8;
		int value;
	public:
		Fixed(void);
		Fixed(const int val);
		Fixed(const Fixed &copy);
		Fixed(const float val);
		~Fixed(void);

		void operator=(const Fixed &copy);
		Fixed	operator+(const Fixed &n) const;
		Fixed	operator-(const Fixed &n) const;
		Fixed	operator*(const Fixed &n) const;
		Fixed	operator/(const Fixed &n) const;

		bool	operator>(const Fixed &n) const;
		bool	operator<(const Fixed &n) const;
		bool	operator>=(const Fixed &n) const;
		bool	operator<=(const Fixed &n) const;
		bool	operator==(const Fixed &n) const;
		bool	operator!=(const Fixed &n) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		int	getRawBits(void) const;
		void setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;

		const static Fixed&	min(const Fixed &a, const Fixed &b);
		const static Fixed&	max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed);