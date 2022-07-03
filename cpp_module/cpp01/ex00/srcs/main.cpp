/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:53:11 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 18:24:15 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string name[] = {"Mark", "Cindy", "Bob", "Hangman"};
	Zombie*	zombie;

	zombie = newZombie("Anna");
	zombie->announce();

	for (int i = 0; i < 4; i++)
		randomChump(name[i]);
	delete	zombie;
	return (0);
}
