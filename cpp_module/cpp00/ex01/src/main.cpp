/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:25:47 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/01 03:04:01 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string cmd;
	Phonebook	phonebook;

	while (1){
		std::cout<< "Enter the command 'EXIT, ADD, SEARCH >>";
		std::getline(std::cin, cmd);

		if(!cmd.compare("EXIT"))
			exit(0);
		else if (!cmd.compare("ADD"))
			phonebook.addContact();
		else if (!cmd.compare("SEARCH")){
			phonebook.displayContacts();
			std::cout <<"Enter the index of the contact number you wnat to see. >>";
			phonebook.searchContact();
			std::cin.ignore();
		}
		else
			continue;
	}
}
