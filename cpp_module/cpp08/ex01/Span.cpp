#include "Span.hpp"
#include <algorithm>

Span::Span(): _max(0)
{
}

Span::Span(const Span & src): _max(src._max), _list(src._list)
{
}

Span::Span(unsigned int n): _max(n)
{
}

Span::~Span()
{
}

Span &				Span::operator=(Span const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

std::ostream &			operator<<(std::ostream & out, Span const & i)
{
	std::vector<int>	list = i.getList();

	for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != list.end())
			std::cout << " ; ";
	}
	return out;
}

void	Span::addNumber(int const nb)
{
	if (_list.size() >= _max)
		throw SizeMaxReachedException();
	_list.push_back(nb);
}

unsigned int	Span::shortestSpan(void) const
{
	if (!_list.size())
		throw NoNumberException();
	else if (_list.size() == 1)
		throw OnlyOneNumberException();
	std::vector<int>	list(_list);
	unsigned int		span = longestSpan();

	std::sort(list.begin(), list.end());
	for (std::vector<int>::iterator i = list.begin(); i < list.end() - 1; i++)
	{
		if (static_cast<unsigned int>(*(i + 1) - *i) < span)
			span = *(i + 1) - *i;
	}
	return (span);
}

unsigned int	Span::longestSpan(void) const
{
	if (!_list.size())
		throw NoNumberException();
	else if (_list.size() == 1)
		throw OnlyOneNumberException();
	std::vector<int>	list(_list);

	std::sort(list.begin(), list.end());
	return (*(list.end() - 1) - *list.begin());
}

std::vector<int>	Span::getList(void) const
{
	return (_list);
}