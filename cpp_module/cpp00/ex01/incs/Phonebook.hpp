/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:03:44 by jihoh             #+#    #+#             */
/*   Updated: 2022/05/28 22:17:57 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>

# define MaxIndex 8

class Phonebook
{
private:
	Contact	contacts[MaxIndex];
	int		cnt;
public:
	Phonebook();
	~Phonebook();
	void	add_contact(void);
	void	search_contact(void);
	void	display_search_prompt(void);
};

#endif