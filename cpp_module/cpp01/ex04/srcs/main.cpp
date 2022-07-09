/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:33:28 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/09 17:51:51 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ReplaceStr.hpp"

int	main(int ac, char **av)
{
	ReplaceStr	rs;

	if (ac != 4)
	{
		std::cout << "./replace [filename] [s1] [s2]" << std::endl;
		return (1);
	}
	rs.replaceStr(av[1], av[2], av[3]);
	return (0);
}
