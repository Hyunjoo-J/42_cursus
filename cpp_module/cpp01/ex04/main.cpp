/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:33:28 by hyjeong           #+#    #+#             */
/*   Updated: 2022/07/11 16:14:13 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char **argv) {
  if (argc != 4)
    return (0);

  std::ifstream ifs;
  ifs.open(argv[1], std::ifstream::in);
  if (!ifs.is_open()){
    std::cout << "Fail to file open\n";
    return (1);
  }

  std::stringstream buf;
  buf << ifs.rdbuf();
  ifs.close();

  std::string str;
  str = buf.str();

  std::string s1 = argv[2];
  std::string s2 = argv[3];

  std::size_t search = 0;
  while (1) {
    search = str.find(s1, search);
    if (search == std::string::npos)
      break;
    else {
      str.erase(search, s1.length());
      str.insert(search, s2);
      search += s2.length();
    }
  }

  std::string ofs = argv[1];
  ofs.append(".replace");

  std::ofstream output;
  output.open(ofs, std::ofstream::out | std::ofstream::trunc);
  if (!output.is_open()){
    std::cout << "Fail to file open\n";
    return (1);
  }

  output << str;

  return (0);
}
