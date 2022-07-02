/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:27:28 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 02:27:31 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_H
# define HUMANB_CLASS_H
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon	*weapon;

public:
	HumanB();
	~HumanB();
	HumanB( std::string name );
	void	attack( void );
	void	setWeapon( Weapon &weapon );
};

#endif