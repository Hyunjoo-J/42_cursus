/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:53:11 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 18:28:56 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

int main()
{
	std::string name[] = {"Mark", "Cindy"};

	Zombie *zombies;
	for (int i = 0; i < 2; i++)
	{
		zombies = zombieHorde(i + 3, name[i]);
		delete[] zombies;
	}
	return (0);
}
