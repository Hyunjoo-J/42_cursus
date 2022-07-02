/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:43:47 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 03:04:33 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP
# include <iostream>
# include <string>
# include <fstream>

class replace
{
private:
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string	s1;
	std::string	s2;
public:
	replace();
	~replace();
	bool	openFile(std::string file);
	void	replaceS(std::string file, std::string s1, std::string s2);
};

replace::replace()
{
}

replace::~replace()
{
}

#endif