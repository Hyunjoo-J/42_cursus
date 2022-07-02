/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:43:59 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 03:06:15 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/replace.hpp"

bool	replace::openFile( std::string f )
{
	this->ifs.open(f, std::ifstream::in);
	if (!this->ifs.is_open())
	{
		std::cout << "Fail to open file." << std::endl;
		return (false);
	}
	else
	{
		this->ofs.open(f.append(".replace"), std::ofstream::out | std::ofstream::trunc);
		if (!this->ofs.is_open())
		{
			std::cout << "Fail to open file." << std::endl;
			return (false);
		}
		return (true);
	}
}

void	replace::replaceS( std::string f, std::string s1, std::string s2 )
{
	std::string		line;
	std::size_t		pos;

	if (replace::openFile(f) == false)
		return ;
	this->s1 = s1;
	this->s2 = s2;
	while (getline(ifs, line))
	{
		if ((pos = line.find(this->s1)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, this->s2);
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}