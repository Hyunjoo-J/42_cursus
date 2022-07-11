/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:48:01 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/11 19:32:04 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : n(0) {
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed) {
	//std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::Fixed(const int num) : n(num << Fixed::bits) {
	//std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num)
	: n(static_cast<int>(roundf(num * (1 << Fixed::bits)))) {
	//std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	//std::cout << "Copy assignment operator called\n";
	if (this != &fixed)
		n = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	//std::cout << "Destructor called\n";
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

bool Fixed::operator>(const Fixed& f){
	return n > f.getRawBits();
}

bool Fixed::operator<(const Fixed& f) {
	return n < f.getRawBits();
}

bool Fixed::operator>=(const Fixed& f) {
	return n >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed& f) {
	return n <= f.getRawBits();
}

bool Fixed::operator==(const Fixed& f) {
	return n == f.getRawBits();
}

bool Fixed::operator!=(const Fixed& f) {
	return n != f.getRawBits();
}

Fixed Fixed::operator+(const Fixed& f) {
  Fixed temp(this->toFloat() + f.toFloat());

  return temp;
}

Fixed Fixed::operator-(const Fixed& f) {
  Fixed temp(this->toFloat() - f.toFloat());

  return temp;
}

Fixed Fixed::operator*(const Fixed& f) {
  Fixed temp(this->toFloat() * f.toFloat());

  return temp;
}

Fixed Fixed::operator/(const Fixed& f) {
  Fixed temp(this->toFloat() / f.toFloat());

  return temp;
}

Fixed& Fixed::operator++(void) {
	++n;
	return *this;
}

Fixed& Fixed::operator--(void) {
	--n;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;

	++n;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;

	--n;
	return temp;
}

Fixed* Fixed::fmin(Fixed* lhs, Fixed* rhs) {
	if ((*lhs).getRawBits() < (*rhs).getRawBits())
		return lhs;
	return rhs;
}

Fixed* Fixed::fmax(Fixed* lhs, Fixed* rhs) {
	if ((*lhs).getRawBits() > (*rhs).getRawBits())
		return lhs;
	return rhs;
}

const Fixed& Fixed::fmin(const Fixed& lhs, const Fixed& rhs) {
	if (lhs.getRawBits() < rhs.getRawBits())
		return lhs;
	return rhs;
}

const Fixed& Fixed::fmax(const Fixed& lhs, const Fixed& rhs) {
	if (lhs.getRawBits() > rhs.getRawBits())
		return lhs;
	return rhs;
}
