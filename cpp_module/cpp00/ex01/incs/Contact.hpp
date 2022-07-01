/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:55:36 by jihoh             #+#    #+#             */
/*   Updated: 2022/05/28 22:17:41 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	std::string	info[5];
	int			contact_index;
	enum InfoIndex {
		FirstName = 0,
		LastName,
		NickName,
		PhoneNumber,
		DarkestSecret
	};
public:
	Contact();
	~Contact();
	void		set_contact_info(int index);
	std::string	info_index_name(int i);
	std::string	substr_info(int i);
	void		display_search_header(void);
	void		display_all_info(void);
};

#endif