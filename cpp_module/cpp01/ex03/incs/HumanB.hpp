/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:27:28 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/09 17:51:16 by hyjeong          ###   ########.fr       */
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
