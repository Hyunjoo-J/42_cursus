#include "iter.hpp"

int main(void)
{
	int arr1[5] = {10, 20, 30, 40, 50};
	iter(arr1, 5, print);

	char arr2[3] = {'a', 'b', 'c'};
	iter(arr2, 3, print);

	std::string arr3[5] = {"hello", "nice", "to", "meet", "you"};
	iter(arr3, 5, print);

	return (0);
}