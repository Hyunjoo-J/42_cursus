/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:26:01 by hyjeong           #+#    #+#             */
/*   Updated: 2022/06/29 20:31:25 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_naem;
	std::string nickname;
	std::string phone_number;
	std::string secret;
public:
	Contact();
	~Contact();
	void	get_FirstName(std::string first);
	void	get_LastName(std::string last);
	void	get_NickName(std::string nick);
	void	get_PhoneNumber(std::string phone);
	void	get_Secret(std::string sec);

	std::string	show_FirstName(void);
	std::string	show_LastName(void);
	std::string	show_NickName(void);
	std::string	show_PhoneNumber(void);
	std::string	show_Secret(void);

};

#endif
