/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:31:39 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/01 03:16:52 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"


class Phonebook {
	private: 
		Contact contact[8];
		int _addNum;
		void displayColumns();

	public:
		Phonebook();
		void addContact();
		void displayContacts();
		void searchContact();
};

#endif
