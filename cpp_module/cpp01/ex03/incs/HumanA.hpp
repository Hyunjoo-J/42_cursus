/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:24:55 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/09 17:51:24 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H
# include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon &weapon;
public:
	~HumanA();
	HumanA(std::string name, Weapon &weapon);
	void	attack(void);
};

#endif
