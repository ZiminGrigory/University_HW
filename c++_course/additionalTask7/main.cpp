#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <mTime.h>

using namespace std;

int getDistance(int a1, int b1, int a2, int b2) {
	return (a1-a2)*(a1-a2)+(b1-b2)*(b1-b2);
}

bool checkDivisions(const vector<int>& a, int el) {
	for (size_t i = 0; i < a.size(); i++) {
		if (a[i]%el) {
			return false;
		}
	}
	return true;
}

int NOD(int a, int b)
{
	while(a > 0 && b > 0)
		if(a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}

int main()
{
//	1
//	cout << "Hello World!" << endl;
//	int a,b;
//	vector<pair<int,int> > coords;
//	int mmax = -1;
//	cin >> a >> b;
//	while (a!=0 && b!=0) {
//		for (size_t i = 0; i < coords.size(); i++) {
//			mmax = max(mmax, getDistance(a,b,coords[i].first, coords[i].second));
//		}
//		coords.push_back(make_pair(a,b));
//		cin >> a >> b;
//	}
//	cout << sqrt(mmax);

//	2
	char *str = "aaaaabbb";
	int mmin = 100000000;
	vector<int> counts(1, 1);
	char c = str[0];
	bool first = true;
	int n = strlen(str);
	for (int i = 1; i <= n; i++) {
		char c2 = str[i];
		if (c == c2) {
			counts.back()++;
		} else {
			if (first) {
				mmin = counts.back();
				first = false;
			}
			c = c2;
			mmin = NOD(mmin, counts.back());
			counts.push_back(1);
		}
	}

	if (mmin >= 2) {
		cout << "yes";
	} else {
		cout << "no";
	}


	//3
	timeCollection tc;
	tc.add(new mTime(2,15));
	tc.add(new time_with_sec(2,15,24));
	timeCollection tc2(tc);
	tc = tc2;
	tc = tc;


	return 0;
}

