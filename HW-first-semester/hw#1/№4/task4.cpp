#include <iostream>
int sum (int x)
{ 
	int s = x / 100 + x / 10 % 10 + x % 10;
	return s;
}
int main ()
{
	int y[27];
	int i = 0;
	for (i = 0; i <= 27; i++)
		y[i] = 0;
	y[0] = 1;
	for (i = 1; i <= 999; i++)
		y[sum (i)]++;
	int s = 0;
	for (i = 0; i <= 27; i++)
		s = s + y[i] * y[i];
	std::cout << "Number of win ticket is" << s;
	std::cin >> s;
}