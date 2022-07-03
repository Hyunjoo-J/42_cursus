/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:49:41 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 18:27:32 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H
# include <iostream>
# include <string>

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	Zombie( std::string name );
	~Zombie();
	void	announce( void );
	void	set_name( std::string name );
};
Zombie* zombieHorde( int N, std::string name );

#endif
