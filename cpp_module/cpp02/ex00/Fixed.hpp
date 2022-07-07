/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:22:07 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/08 02:36:12 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# pragma once

class Fixed
{
private:
	int n;
	static const int	bits;
public:
	Fixed();
	Fixed(const Fixed &Fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	
	int  getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
