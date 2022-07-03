/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceStr.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:33:22 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/03 14:34:16 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACESTR_CLASS_H
# define REPLACESTR_CLASS_H

# include <iostream>
# include <fstream>
# include <string>

class ReplaceStr
{
private:
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		s1;
	std::string		s2;

public:
	ReplaceStr();
	~ReplaceStr();
	bool	openFile( std::string f );
	void	replaceStr( std::string f, std::string s1, std::string s2 );
};

#endif
