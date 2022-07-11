/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:22:07 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/11 19:28:05 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# pragma once
# include <iostream>

class Fixed
{
private:
	int n;
	static const int	bits = 8;
public:
	Fixed(void);
	Fixed(const Fixed &Fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed(void);

	int  getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
