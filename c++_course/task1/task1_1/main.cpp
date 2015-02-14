#include <iostream>

using namespace std;

int main()
{
	// 1
	cout << "first: \n" << "enter n -->:";
	int n(0);
	cin >> n;
	double sum(1.);
	double sign(1.);
	if (n > 0){
		for (int i = 3; i <= 2*n + 1; i += 2){
			sign = -sign;
			sum += sign / double(i * i);
		}
	}
	cout << sum;

	return 0;
}

