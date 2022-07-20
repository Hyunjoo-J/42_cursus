#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <typeinfo>
#include <stack>
#include <iostream>

class WrongContainerException: public std::exception
{
	const char * what() const throw()
	{
		return ("Error: wrong container type");
	}
};

template <typename T>
typename T::iterator	easyfind(T & container, int value)
{
	if (typeid(T) != typeid(std::vector<int>)
			&& typeid(T) != typeid(std::deque<int>)
			&& typeid(T) != typeid(std::list<int>)
			&& typeid(T) != typeid(std::map<int, int>)
			&& typeid(T) != typeid(std::set<int>))
	{
		throw WrongContainerException();
	}
	return (std::find(container.begin(), container.end(), value));
}

#endif