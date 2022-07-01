/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:06:07 by jihoh             #+#    #+#             */
/*   Updated: 2022/05/28 22:22:39 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	Phonebook::add_contact(void)
{
	contacts[cnt % MaxIndex].set_contact_info(cnt % MaxIndex);
	cnt++;
	std::cout << "\033[0;32mAdded successfully!\033[0m" << std::endl;
}

void	Phonebook::search_contact(void)
{
	int	index;

	Phonebook::display_search_prompt();
	std::cout << "Enter index want to search(exit: -1): ";
	while (1)
	{
		std::cin >> index;
		if (index == -1)
			break ;
		else if (index < 1 || index > cnt || index > MaxIndex || std::cin.fail())
		{
			std::cout << "\033[0;31mInvalid index. Please try it again.\033[0m" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
		else
			this->contacts[index - 1].display_all_info();
		std::cout << "Enter index want to search(exit: -1): ";
	}
}

void	Phonebook::display_search_prompt(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < cnt && i < MaxIndex; i++)
		this->contacts[i].display_search_header();
	std::cout << "|-------------------------------------------|" << std::endl;
}

Phonebook::Phonebook()
{
	this->cnt = 0;
}

Phonebook::~Phonebook()
{
}
