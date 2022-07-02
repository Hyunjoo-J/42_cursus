/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:53:11 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 01:17:09 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string name[] = {"Mark", "Cindy", "Bob", "Hangman"};
	Zombie	zombie;

	for (int i = 0; i < 4; i++)
		zombie.randomChump(name[i]);
	zombie.announce();
	return (0);
}