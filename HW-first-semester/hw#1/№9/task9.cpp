#include <iostream>
int main()
{
	std::cout << "Hello!" << std::endl;
	int x = 0;
	std::cout << "Please enter x " << std::endl;
	std::cin >> x;
	int n = 0;
	std::cout << "Please enter n " << std::endl;
	std::cin >> n;
	int result = x;
	int i = 0;
	for (i = 2; i <= n; i++)
		result = result * x;
	std::cout << "result="<< result << std::endl;
	std::cin >> x;

}