#include <iostream>
int main()
{
	std::cout << "Hello!" << std::endl;
	int x = 0;
	std::cout << "Please enter x" << std::endl;
	std::cin >> x;
	int y = 0;
	std::cout << "Please enter y" << std::endl;
	std::cin >> y;
	int i = 0;
	while (x >= y) 
	 {
		i = i + 1;
		x = x - y;
	 }
	
	std::cout << "partial quotient="<< i << std::endl;
	std::cin >> x;

}