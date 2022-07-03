/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:30:26 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 19:05:47 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::attack(void)
{
	if (!(this->weapon)){
		std::cout << "no weapon" << std::endl;
		return;
	}
	else
		std::cout << this->name << "attacks with their " << this->weapon->getType() << std::endl;

}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

HumanB::HumanB()
{
}

HumanB::~HumanB()
{
}
