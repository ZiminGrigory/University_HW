#include <iostream>
int swap( int &x, int &y)
 {
	x = x + y;
	y = x - y;
	x = x - y;
	return x, y;
 }

int main()
{
	int m = 0;
	int n = 0;
	std::cout << "Hello, enter m and n" << std::endl;
	std::cin >> m >> n;
	int x[10];
	int i = 0;
	std::cout << "Please, enter x" << std::endl;
	for (i = 1; i <= m + n; i++)
		std::cin >> x[i];
	for (i = 1; i <= m / 2; i++)
		swap(x[i], x[m + 1 - i]);	
	for (i = 1; i <= n / 2; i++)
		swap(x[m + i], x[m + n + 1 - i]);	
	for (i = 1; i <= (m + n) / 2; i++)
		swap(x[i], x[m + n + 1 - i]);	
	for (i = 1; i <= m + n; i++)
		std::cout << x[i];
	std::cin >> m;

}