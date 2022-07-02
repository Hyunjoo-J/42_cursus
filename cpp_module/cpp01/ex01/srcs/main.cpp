/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:53:11 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 01:47:35 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

int main()
{
	std::string name[] = {"Mark", "Cindy"};
	Zombie	zombie;
	Zombie *zombies;

	for (int i = 0; i < 2; i++)
	{
		zombies = zombie.zombieHorde(i + 1, name[i]);
		delete[] zombies;
	}
	return (0);
}