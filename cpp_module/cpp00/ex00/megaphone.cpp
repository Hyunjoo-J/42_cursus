/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:19:49 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/01 20:19:51 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	char	*s;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
		return (0);
	}
	av++;
	while (*av)
	{
		s = *av;
		while (*s)
		{
			*s = std::toupper(*s);
			s++;
		}
		std::cout << *av++;
	}
	std::cout << std::endl;
	return (0);
}
