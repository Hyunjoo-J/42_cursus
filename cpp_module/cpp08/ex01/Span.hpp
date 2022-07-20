#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>

class Span
{
	public:
		Span();
		Span(Span const & src);
		Span(unsigned int n);
		~Span();

		void				addNumber(int const nb);
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;
		std::vector<int>	getList(void) const;

		template<typename InputIterator>
		void	addRange(InputIterator first, InputIterator last);

		class SizeMaxReachedException: public std::exception
		{
			const char * what() const throw()
			{
				return ("Error: maximum size has been reached...");
			}
		};

		class NoNumberException: public std::exception
		{
			const char * what() const throw()
			{
				return ("Error: array is empty...");
			}
		};

		class OnlyOneNumberException: public std::exception
		{
			const char * what() const throw()
			{
				return ("Error: only one number in array...");
			}
		};

	private:
		const unsigned int	_max;
		std::vector<int>	_list;
		Span &		operator=(Span const & rhs);
};

template<typename InputIterator>
void	Span::addRange(InputIterator first, InputIterator last)
{
	while (first != last)
	{
		if (_list.size() >= _max)
			throw SizeMaxReachedException();
		_list.push_back(*first);
		first++;
	}
}

std::ostream &			operator<<(std::ostream & out, Span const & i);

#endif