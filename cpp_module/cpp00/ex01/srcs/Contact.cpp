/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:22:05 by jihoh             #+#    #+#             */
/*   Updated: 2022/05/28 22:19:34 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set_contact_info(int index)
{
	this->contact_index = index + 1;
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << info_index_name(i) << ": ";
		std::cin >> info[i];
	}
}

std::string	Contact::info_index_name(int i)
{
	if (i == FirstName)
		return ("First name");
	else if (i == LastName)
		return ("Last name");
	else if (i == NickName)
		return ("Nickname");
	else if (i == PhoneNumber)
		return ("Phone number");
	else if (i == DarkestSecret)
		return ("Darkest secret");
	else
		return (NULL);
}

std::string	Contact::substr_info(int i)
{
	if (this->info[i].length() > 10)
		return (this->info[i].substr(0, 9) + ".");
	else
		return (this->info[i]);
}

void Contact::display_search_header(void)
{
	std::cout << "|" << std::setw(10) << this->contact_index;
	std::cout << "|" << std::setw(10) << substr_info(FirstName);
	std::cout << "|" << std::setw(10) << substr_info(LastName);
	std::cout << "|" << std::setw(10) << substr_info(NickName) << "|" << std::endl;
}

void Contact::display_all_info(void)
{
	for (int i = FirstName; i <= DarkestSecret; i++)
		std::cout << info_index_name(i) << ": " << this->info[i] << std::endl;
}

Contact::Contact()
{
}
Contact::~Contact()
{
}
