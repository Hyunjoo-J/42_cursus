/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:16:43 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 02:22:39 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H
# include <iostream>
# include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon();
	~Weapon();
	Weapon(std::string type);
	const std::string	&getType(void) const;
	void	setType(std::string type);
};

#endif