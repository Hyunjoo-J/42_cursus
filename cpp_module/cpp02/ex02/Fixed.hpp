/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:45:37 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/09 02:00:35 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# pragma once
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int n;
	static const int	bits = 8;
public:
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed& f);
	bool operator<(const Fixed& f);
	bool operator>=(const Fixed& f);
	bool operator<=(const Fixed& f);
	bool operator==(const Fixed& f);
	bool operator!=(const Fixed& f);

	Fixed operator+(const Fixed& f);
	Fixed operator-(const Fixed& f);
	Fixed operator*(const Fixed& f);
	Fixed operator/(const Fixed& f);

	Fixed& operator++(void);
	Fixed& operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	Fixed& operator=(const Fixed& f);
	Fixed(void);
	explicit Fixed(const int v);
	explicit Fixed(const float v);
	Fixed(const Fixed& f);
	~Fixed(void);

	static Fixed* fmin(Fixed* lhs, Fixed* rhs);
	static Fixed* fmax(Fixed* lhs, Fixed* rhs);
	static const Fixed& fmin(const Fixed& lhs, const Fixed& rhs);
	static const Fixed& fmax(const Fixed& lhs, const Fixed& rhs);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
