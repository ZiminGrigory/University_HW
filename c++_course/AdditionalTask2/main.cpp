#include <iostream>

using namespace std;

int getNearest(const int* const array, int n, const int number)
{
	auto a = array;
	int i = n / 2;
	while (!(a[i] <= number && number <= a[i+1]) && !(i == 0) && !(i == n-2))
		if (a[i] <= number)
			i += (n-i)/2;
		else
			i -= (n-i)/2;
	return abs(a[i] - number) <= abs(a[i+1] - number) ? a[i]: a[i+1];
}

bool compare(const char* const s1, const char* const s2)
{
	auto s1_ = s1;
	auto s2_ = s2;
	bool ans(true);
	while (ans && *s1_ != '\0' && *s2_ != '\0') {
		while (*s1_ == ' ') {
			s1_++;
		}

		while (*s2_ == ' ') {
			s2_++;
		}
		if (*s1_ != '\0' && *s2_ != '\0')
			ans = *s1_ == *s2_, s1_++, s2_++;
	}

	while (*s1_ == ' ') {
		s1_++;
	}

	while (*s2_ == ' ') {
		s2_++;
	}
	return ans && *s1_ == '\0' && *s2_ == '\0';
}

int main()
{
	const int a[10] {-3, -2, 0, 1, 3, 5, 7, 10, 20, 23};
	cout << (getNearest(a, 10, -3) == -3) << "\n";
	cout << (getNearest(a, 10, 2) == 1) << "\n";
	cout << (getNearest(a, 10, 22) == 23) << "\n";
	cout << (getNearest(a, 10, 25) == 23) << "\n";
	cout << (getNearest(a, 10, -233) == -3) << "\n";

	//
	char s1[100];
	char s2[100];
	cout << "enter couple lines pls\n";
	cin.getline(s1, 100);
	cin.getline(s2, 100);
	cout << " compare2 s1 s2 = " << compare(s1, s2) << endl;

	return 0;
}

