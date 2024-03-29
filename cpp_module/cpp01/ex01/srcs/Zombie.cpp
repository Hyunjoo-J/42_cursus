/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:54:56 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/09 17:34:08 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie::Zombie()
{
	this->name = "Foo";
}

Zombie::Zombie( std::string name )
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " delete" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name( std::string name )
{
	this->name = name;
}
