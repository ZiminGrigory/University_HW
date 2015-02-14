#include <iostream>

using namespace std;

int func1(int n){		//return number of fives in n!
	int x(5), s(0);
	while (x <= n)
	{
		s += n / x;
		x *= 5;
	}
	return s;
}

int func2(int n){		//return last nonzero digit of n!, when n <= 10 without 5
	switch (n)
	{
		case 0:
			return 1;
		break;
		case 1:
			return 1;
		break;
		case 2:
			return 2;
		break;
		case 3:
			return 6;
		break;
		case 4:
			return 4;
		break;
		case 5:
			return 4;
		break;
		case 6:
			return 4;
		break;
		case 7:
			return 8;
		break;
		case 8:
			return 4;
		break;
		case 9:
			return 6;
		break;
	}
	return 0;
}

int func3(int n){		//return the last digit of 3^k
	switch (n % 4){
		case 0:
			return 1;
		break;
		case 1:
			return 3;
		break;
		case 2:
			return 9;
		break;
		case 3:
			return 7;
		break;
	}
	return 0;
}

int main()
{
	// 3 last nonzero digit of n!
	int n(0);
	cout << "last nonzero digit of n!, 1 <= n <= 100000: \n" << "enter n -->:";
	cin >> n;
	int answer(1);
	int numberOfFives(func1(n));
	if ((n != 0) && (n != 1)){
		while (n > 0){
			answer = (answer * func2(n % 10)) % 10;
			n = n / 5;
		}
		answer = (6 * answer * func3(numberOfFives)) % 10;
	}
	cout << "last non zero digit: " << answer;
	return 0;
}

