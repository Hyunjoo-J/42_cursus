/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:10:29 by hyjeong           #+#    #+#             */
/*   Updated: 2022/06/29 16:27:52 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <iostream>

int	main(int argc, char **argv)
{
	std::string str;

	if (argc == 1)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (isalpha(argv[i][j]))
				std::cout<<(char)std::toupper(argv[i][j]);
			else if (argv[i][j] == '"')
				continue ;
			else
				std::cout<<argv[i][j];
		}
	}
	std::cout<<std::endl;
	return (0);
}
