/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:16:43 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/09 17:50:16 by hyjeong          ###   ########.fr       */
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
