/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:25:47 by hyjeong           #+#    #+#             */
/*   Updated: 2022/06/29 20:31:27 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	book;
	std::string	input;

	std::cout<<"Input a command: ADD, SEARCH, EXIT\n";
	while (true)
	{
		std::cin>>input;
		if (input == "EXIT")
			book.Exit();
		else if(input == "SEARCH")
			book.Search();
		else if (input == "ADD")
			book.Add();
		else
		{
			std::cout<<"Input a command: ADD, SEARCH, EXIT\n";
			continue ;
		}
	}
	return (0);
}
