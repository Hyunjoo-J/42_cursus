/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:24:55 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 02:38:19 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H
# include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon *weapon;
public:
	HumanA();
	~HumanA();
	HumanA(std::string name, Weapon &weapon);
	void	attack(void);
};

#endif