#include "Fixed.hpp"

Fixed::Fixed(void) : n(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::Fixed(const int num) : n(num << Fixed::bits) {
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num)
	: n(static_cast<int>(roundf(num * (1 << Fixed::bits)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called\n";
	if (this != &fixed)
		n = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
	return n;
}

void Fixed::setRawBits(const int raw) {
	n = raw;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(n) / (1 << bits));
}

int Fixed::toInt(void) const {
	return n >> Fixed::bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	return out << fixed.toFloat();
}