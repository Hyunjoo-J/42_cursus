/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:48:24 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 02:00:03 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "address PTR : " << stringPTR << std::endl;
	std::cout << "address REF : " << &stringREF << std::endl;
	std::cout << "value PTR : " << *stringPTR << std::endl;
	std::cout << "value REF : " << stringREF << std::endl;

	return (0);
}