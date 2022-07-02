/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:44:02 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 02:59:27 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/replace.hpp"

int main(int argc, char **argv)
{
	replace	rp;

	if (argc != 4)
	{
		std::cout << "./replace [filename] [s1] [s2]" << std::endl;
		return (1);
	}
	rp.replaceS(argv[1], argv[2], argv[3]);
	return (0);
}