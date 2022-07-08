/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:45:37 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/09 01:10:04 by hyunjoo          ###   ########.fr       */
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

	Fixed& operator=(const Fixed& f);
	Fixed(void);
	explicit Fixed(const int v);
	explicit Fixed(const float v);
	Fixed(const Fixed& f);
	~Fixed(void);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
