#include <iostream>
int main()
{
	std::cout << "Hello!" << std::endl;
	int x;
	std::cout << "Please enter x " << std::endl;
	std::cin >> x;
	int y = x * x;
	x = (y + 1) * (y + x) + 1;
	std::cout << "x="<< x << std::endl;
	std::cin >> x;

}